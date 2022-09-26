struct Operation {
    int type; //1 for read, 2 for write
    int key;
    int value;
    int clientId ;
    int serverId;
    int transId;
    simtime_t ts;
};


message Transaction{
    
    Operation operations[2];
    
}


message DoOperation{
    
    Operation op;
    
}

message Ack{
    int serverId;
    simtime_t ts;
    int clientId;
    
}

message Nack{
    int serverId;
    simtime_t ts;
    int clientId;
}

message Commit{
    int serverId;
    simtime_t ts;
    int clientId;
}

message Abort{
    int serverId;
    simtime_t ts;
    int clientId;
}

message WriteVal{
	int key;
	int value;
} 

message ReadVal{
    int key;
    int value;
    int clientId;
}