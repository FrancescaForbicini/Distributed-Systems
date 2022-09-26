#include <omnetpp.h>
#include<message_m.h>

using namespace omnetpp;
using namespace std;

class Client: public cSimpleModule {
public:
    cMessage *needResEvt;
    cMessage *resend;
    Operation *curOp;

    int numKey;
    int numServer;
    int maxVal;
    int numOpInT;

    simtime_t startWaitingTime;  //for simulation
    cOutVector waitingTime;
    cOutVector ackCounter;

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finalize();
};

Define_Module(Client);

void Client::initialize() {
    numKey = par("k");
    numServer = par("n");
    maxVal = par("v");
    numOpInT = par("t");
    curOp = new Operation[numOpInT];


    needResEvt = new cMessage("Need");
    resend = new cMessage("Resend");
    scheduleAt(simTime()+par("reqPeriod"), needResEvt);

    waitingTime.setName("WaitingTime");
    ackCounter.setName("AckCounter");
}

void Client::finalize() {
    /*
    cancelAndDelete(needResEvt);
    cancelAndDelete(finishedUsingResEvt);
*/
}

void Client::handleMessage(cMessage *msg) {
    if(msg==needResEvt) {

        int oper;

        EV << "I need accessing resource" << endl;

        startWaitingTime = simTime();

        Transaction *msg = new Transaction("Trans");

        srand(time(NULL));
        simtime_t temp = simTime();
        for(int i = 0; i< msg->getOperationsArraySize();i++){  //for each operation in the transaction
            Operation *op = new Operation();
            /*oper = (rand()%10)+1;
            {
                if (oper <= 9){
                    op -> type = 2;
                }else
                {
                    op -> type = 1;
                }
            }*/
            op -> type = (rand()%2)+1;  //1 for read,  2 for write

            op -> key = (rand()%numKey);
            op -> value = (rand()%maxVal);
            op -> clientId = this->getIndex();
            op -> serverId = (rand()%numServer);
            //op -> serverId = 1;  //TODO: test purpose
            op -> ts = temp;
            msg -> setOperations(i,*op);
            curOp[i] = *op;
        }

        send(msg,"gateC$o");

    } else if (std::strcmp(msg->getName(),"Ack") == 0){ //response for transaction
        EV << "Finished using the resource" << endl;
        waitingTime.record(simTime()-startWaitingTime);
        ackCounter.record(1);
        cancelAndDelete(msg);
        scheduleAt(simTime()+par("reqPeriod"), needResEvt);

    }else if (std::strcmp(msg->getName(),"Nack") == 0){  //response for transaction
        waitingTime.record(simTime()-startWaitingTime);
        ackCounter.record(0);
        EV << "Nack received, resend the transaction!" << endl;
        cancelAndDelete(msg);

        volatile double resendTime = (rand()%60) +30;
        scheduleAt(simTime()+resendTime, resend);

    }else if(std::strcmp(msg->getName(),"ReadVal") == 0){
        ReadVal *a = check_and_cast<ReadVal *>(msg);
        EV<<"Key: " << a->getKey() << " value: " << a->getValue() << endl;
        cancelAndDelete(msg);
    }else if(msg == resend){  //resend the transaction after a nack

        Transaction *curTrans = new Transaction("Trans");
        simtime_t temp = simTime();
        for(int j = 0; j < numOpInT; j++){
            curOp[j].ts = temp;
            curTrans -> setOperations(j,curOp[j]);
        }

        startWaitingTime = simTime();
        send(curTrans,"gateC$o");
    }
}
