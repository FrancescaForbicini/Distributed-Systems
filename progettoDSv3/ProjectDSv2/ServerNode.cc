#include <omnetpp.h>
#include <queue>
#include <message_m.h>
#include <vector>

using namespace omnetpp;
using namespace std;

struct controlKey{
    int key;
    int val;
    simtime_t RTM;
    simtime_t WTM;
};

struct tempWrite{
    int key;
    int val;
    simtime_t ts;   //when it commits, it became the WTM
    int clientIs;   //to distinguish on commit
};

struct readToCheck{
    Operation op;
    int receiver;
};

struct readToSend{
    int key;
    int value;
    int clientId;
    simtime_t ts;
};


class ServerNode : public cSimpleModule {
private:
    int numServer;
    int numKey;
    int numReplicas;
    int numOpInT;
    int size;
    int contAck;
    int curClientId; //identificano la transazione attualemtne trattata, per identificare gli ack
    simtime_t curTS;

    vector<tempWrite> tempWrites;
    vector<readToCheck> readsToCheck;
    vector<readToSend> readsToSend;

    int isFree;  //free to handle a new transation



    queue<Transaction> trQueue;  //transaction queue (to handle and distribute)


    int *contactedNodes;
    int contactedNodesSize;

    cMessage *token;
    controlKey *cKey;

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finalize();
    virtual void handleOperation(Operation op, int receiver);
    virtual void sendResponse(int receiver, int response, simtime_t ts, int clientId); //receiver is the receiver index, reponse is 0 far nack, 1 for ack
    virtual void insertContactedNode(int serverId);
    virtual void sendCommit(int clientId, simtime_t ts);
    virtual void sendAbort(int clientId, simtime_t ts);
    virtual void updateValue(int clientId, simtime_t ts, bool valid);  //valid to distinguish between commit and abort
    virtual void checkRead();
    virtual void sendWriteValue();
};

Define_Module(ServerNode);

void ServerNode::initialize() {
    numKey = par("k");
    numServer = par("n");
    numReplicas = par("r");
    numOpInT = par("t");
    contAck = 0;
    size = numKey/numServer + 1;
    isFree = 1;

    cKey = new controlKey[size];
    contactedNodes = new int[numOpInT];
    contactedNodesSize = 0;

    int j = 0;
    for(int i = 0; i < numKey; i++){
        if(i % numServer == this->getIndex())
        {
            controlKey k;
            k.key = i;
            k.val = 0;
            k.RTM = 0;
            k.WTM = 0;
            cKey[j] = k;
            j++;
            EV << "Server: " << this->getIndex() << " - key: " << i <<endl;
        }
    }
    size = j; //real size of the vector
}

void ServerNode::finalize() {
    /*
    cancelAndDelete(needResEvt);
    cancelAndDelete(finishedUsingResEvt);
*/
}

void ServerNode::handleMessage(cMessage *msg) {

    if(std::strcmp(msg->getName(),"Trans") == 0){
        Transaction *t = check_and_cast<Transaction *>(msg);

        trQueue.push(*t);
        cancelAndDelete(msg);


    }else if(std::strcmp(msg->getName(),"DoOp") == 0){  //we are leader for a key, need to execute an operation
        DoOperation *t = check_and_cast<DoOperation *>(msg);
        Operation op = t->getOp();

        handleOperation(op, msg->getSenderModule()->getIndex());

        cancelAndDelete(msg);

    }else if(std::strcmp(msg->getName(),"Ack") == 0){
        EV <<"Ack ricevuto! " << endl;
        Ack *a = check_and_cast<Ack *>(msg);
        if((curClientId == a->getClientId())&&(curTS == a->getTs())){ //se e per la transazione che sto trattando
            contAck++;
            if(contAck == numOpInT){
                sendCommit(a->getClientId(), a->getTs());
                send(msg, "gateS$o", this->getIndex()); //invio ack al client
                contAck = 0;
                isFree = 1;
                contactedNodesSize = 0;
            }
        }

    } else if(std::strcmp(msg->getName(),"Nack") == 0){
        EV <<"Nack ricevuto! " << endl;
        Nack *na = check_and_cast<Nack *>(msg);
        if((curClientId == na->getClientId())&&(curTS == na->getTs())){

            curClientId = -1;

            sendAbort(na->getClientId(), na->getTs()); //TODO: abort anche quelli di cui sono il leade
            send(msg, "gateS$o", this->getIndex()); //invio abort al client
            contAck = 0;
            isFree = 1;
            contactedNodesSize = 0;
        }
    }else if(std::strcmp(msg->getName(),"Commit") == 0){
        EV<<"Commit received" <<endl;
        Commit *c = check_and_cast<Commit *>(msg);

        for(int i = readsToSend.size() -1; i>=0;i--){
            if(readsToSend[i].clientId == c->getClientId() && readsToSend[i].ts == c->getTs()){
                ReadVal *rv = new ReadVal("ReadVal");
                rv->setValue(readsToSend[i].value);
                rv->setKey(readsToSend[i].key);
                rv->setClientId(c->getClientId());
                send(rv, "gateS$o", this->getIndex());

                readsToSend.erase(readsToSend.begin() + i);
            }
        }

        sendWriteValue();
        updateValue(c->getClientId(), c->getTs(), true);
        checkRead();
        cancelAndDelete(msg);

    }else if(std::strcmp(msg->getName(),"Abort") == 0){

        EV<<"Abort received" <<endl;
        Abort *c = check_and_cast<Abort *>(msg);
        updateValue(c->getClientId(), c->getTs(), false);
        checkRead();
        for(int i = readsToSend.size() -1; i>=0; i--){
            if(readsToSend[i].clientId == c->getClientId() && readsToSend[i].ts == c->getTs()){
                readsToSend.erase(readsToSend.begin() + i);
            }
        }
        cancelAndDelete(msg);

    }else if(std::strcmp(msg->getName(),"WriteVal") == 0){
        WriteVal *w = check_and_cast<WriteVal *>(msg);
        for(int i = 0; i < size; i++){
            if(cKey[i].key == w->getKey()){
                cKey[i].val = w->getValue();
                break;
            }
        }
        cancelAndDelete(msg);
    }

    while(!trQueue.empty() and isFree){
        Transaction t = trQueue.front();
        trQueue.pop();
        isFree = 0;

        int clientId = t.getOperations(0).clientId;
        curClientId = t.getOperations(0).clientId;  //per identificare la transazione che stiamo trattando
        curTS = t.getOperations(0).ts;

        for(int i = 0; i < t.getOperationsArraySize();i++){
            DoOperation *doop = new DoOperation("DoOp");
            doop -> setOp(t.getOperations(i));
            int serverId = t.getOperations(i).key % numServer;
            insertContactedNode(serverId);
            if(t.getOperations(i).key % numServer != this->getIndex()){
                send(doop,"gateS$o",serverId);

            }else{
                //scheduleAt(simTime()+par("delay"), doop);

                handleOperation(t.getOperations(i), this->getIndex()); //if the leader is this server, we don't need to send a message
            }
        }
    }
}



//when the leader node receive an operation to handle
void ServerNode::handleOperation(Operation op, int receiver)
{
    for(int i = 0; i < size; i++){  //for each key handled by the server
        if(op.key == cKey[i].key)
        {
        //Ho trovato la struttura di controllo della key!
        //switch su tipo op e controllo timestamp
        switch(op.type){
            case(1): //read
                if(op.ts < cKey[i].WTM){
                    //non si può eseguire la read!
                    sendResponse(receiver, 0, op.ts, op.clientId);
                }
                else{
                    //controllo le writeTemp e tengo le read in un vettore
                    bool canRead = true;
                    for(int i=0; i < tempWrites.size(); i++){
                        if(tempWrites[i].ts < op.ts){ //write before read --> not good
                            canRead = false;
                        }
                    }

                    if(canRead){
                        cKey[i].RTM = (cKey[i].RTM > op.ts ? cKey[i].RTM : op.ts);

                        readToSend rts;
                        rts.clientId = op.clientId;
                        rts.value = cKey[i].val;
                        rts.ts = op.ts;
                        rts.key = op.key;
                        readsToSend.insert(readsToSend.begin(),rts);

                        sendResponse(receiver, 1, op.ts, op.clientId);
                    }
                    else{  //wait for write to abort or commit

                        readToCheck rtc;
                        rtc.op = op;
                        rtc.receiver = receiver;

                        readsToCheck.insert(readsToCheck.begin(),  rtc);

                        EV <<"Aggiunta readsToCheck" <<endl;
                    }
                }
            break;
            case(2): //write
                if(op.ts < cKey[i].RTM){
                    //non si può scrivere!
                    sendResponse(receiver, 0, op.ts, op.clientId);
                }
                else{
                    //write eseguita nella tempWrite

                    tempWrite temp;
                    temp.key = op.key;
                    temp.ts = op.ts;
                    temp.val = op.value;
                    temp.clientIs = op.clientId;
                    tempWrites.insert(tempWrites.begin(), temp);

                    EV <<"Aggiunta TempWrite" <<endl;

                    sendResponse(receiver, 1, op.ts, op.clientId);
                }
            break;
            }
        }
    }
}

void ServerNode::sendResponse(int receiver, int response, simtime_t ts, int clientId)
{
    if(response == 1){ //ack
        Ack *ack = new Ack("Ack");
        ack -> setServerId(receiver);
        ack -> setTs(ts);
        ack -> setClientId(clientId);
        if(receiver != this -> getIndex()){
            send(ack, "gateS$o", receiver);
        }else{
            scheduleAt(simTime()+par("delay"), ack);
        }

    }else if (response == 0){ //nack



        Nack *nack = new Nack("Nack");
        nack -> setServerId(receiver);
        nack -> setTs(ts);
        nack -> setClientId(clientId);
        if(receiver != this -> getIndex())
        {
            send(nack, "gateS$o", receiver);
        }else{
            scheduleAt(simTime()+par("delay"), nack);
        }
    }
}

void ServerNode::insertContactedNode(int serverId){
    bool present = false;
    for(int i = 0; i < contactedNodesSize; i++){
        if(contactedNodes[i] == serverId){
            present = true;
            break;
        }
    }
    if(!present){
        contactedNodes[contactedNodesSize] = serverId;
        contactedNodesSize++;
    }
}

void ServerNode::sendCommit(int clientId, simtime_t ts){
   for(int i = 0; i< contactedNodesSize; i++){
       Commit *c= new Commit("Commit");
       c->setClientId(clientId);
       c->setTs(ts);
       if(contactedNodes[i] != this->getIndex()){
           send(c, "gateS$o", contactedNodes[i]);
       }
       else{
           scheduleAt(simTime()+par("delay"), c);
       }
   }
}

void ServerNode::sendAbort(int clientId, simtime_t ts){
   for(int i = 0; i< contactedNodesSize; i++){
       Abort *a= new Abort("Abort");
       a->setClientId(clientId);
       a->setTs(ts);
       if(contactedNodes[i] != this->getIndex()){
           send(a, "gateS$o", contactedNodes[i]);
       }
       else{
           scheduleAt(simTime()+par("delay"), a);
       }
   }
}

void ServerNode::updateValue(int clientId, simtime_t ts, bool valid){

    //EV << "Numero di tempWrites prima:" << tempWrites.size() <<endl;

    for(int i = tempWrites.size() - 1; i >= 0 ; i--){
        if(tempWrites[i].ts == ts && tempWrites[i].clientIs == clientId){
            if(valid){
                for(int j = 0; j < size; j++){
                    if(tempWrites[i].key == cKey[j].key){
                        cKey[j].WTM = tempWrites[i].ts;
                        cKey[j].val = tempWrites[i].val;
                    }
                }
            }
            tempWrites.erase(tempWrites.begin() + i);
        }
    }

    //EV << "Numero di tempWrites dopo:" << tempWrites.size() <<endl;
}



void ServerNode::checkRead(){

    //EV << "Numero di readToCheck prima:" << readsToCheck.size() <<endl;
    for(int i = readsToCheck.size() -1; i >= 0; i--){
        /*DoOperation *doop = new DoOperation("DoOp");
        doop -> setOp(readsToCheck[i]);
        scheduleAt(simTime()+par("delay"), doop);*/   //sbagliava il receiver!!
        handleOperation(readsToCheck[i].op, readsToCheck[i].receiver);
        readsToCheck.erase(readsToCheck.begin() + i);
    }
    //EV << "Numero di readToCheck dopo:" << readsToCheck.size() <<endl;
}

void ServerNode::sendWriteValue()
{
    for(int i = 0; i< tempWrites.size(); i++){
        for(int j = 1; j < numReplicas; j++){
            WriteVal *wv = new WriteVal("WriteVal");
            wv->setKey(tempWrites[i].key);
            wv->setValue(tempWrites[i].val);
            send(wv,"gateS$o",(this->getIndex() + j) % numServer);
        }
    }
}


