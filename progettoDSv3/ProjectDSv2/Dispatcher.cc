#include <omnetpp.h>
#include <message_m.h>

using namespace omnetpp;
using namespace std;

class Dispatcher : public cSimpleModule {
private:

    cMessage *token;


protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finalize();
};

Define_Module(Dispatcher);

void Dispatcher::initialize() {

}

void Dispatcher::finalize() {
    /*
    cancelAndDelete(needResEvt);
    cancelAndDelete(finishedUsingResEvt);
*/
}

void Dispatcher::handleMessage(cMessage *msg) {

    if(std::strcmp(msg->getName(),"Trans") == 0){
        Transaction *t = check_and_cast<Transaction *>(msg);
        send(msg,"gateS$o", t->getOperations(0).serverId);

    }else if(std::strcmp(msg->getName(),"Ack") == 0){
        Ack *a = check_and_cast<Ack *>(msg);
        send(msg, "gateC$o", a->getClientId());
    }else if(std::strcmp(msg->getName(),"Nack") == 0){
        Nack *a = check_and_cast<Nack *>(msg);
        send(msg, "gateC$o", a->getClientId());
    }else if(std::strcmp(msg->getName(),"ReadVal") == 0){
        ReadVal *a = check_and_cast<ReadVal *>(msg);
        send(msg, "gateC$o", a->getClientId());
    }
}

