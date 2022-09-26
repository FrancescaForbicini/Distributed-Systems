simple Client {
	parameters: 
	    int k = default(10);
	    int n = default(5);
	    int m = default(2);
	    int v = default(19);
	    int t = default(3);
    	volatile double reqPeriod @unit(s) = default(uniform(0s,1s));
	    
    @display("i=block/process");
	    
	gates:
    	inout gateC;
}

simple Dispatcher {
	parameters:
      
	    int n = default(5);
	    int m = default(2);
        volatile double delay @unit(s) = default(uniform(0.1s,0.2s));
		
   		
  gates:
    inout gateC[m];
    inout gateS[n];
}

simple ServerNode {
	parameters:
		int k = default(10);
	    int n = default(5);
	    int m = default(2);
	    int r = default(1);
	    int t = default(3);
		volatile double delay @unit(s) = default(uniform(0.1s,0.2s));
		
  gates:
    inout gateS[n];  //server i has gateS[i] to communicate with the dispatcher
}



channel MyChannel extends ned.DatarateChannel {
    delay = 100ms;
    datarate = 1024kbps;
}


network progetto{
	parameters:
    	int n = default(5);
		int m = default(1);
    submodules:
    	nodes[n]: ServerNode {    }
    	noded   : Dispatcher {    }
    	nodec[m]: Client     {    }
  connections:
    for i=0..m-1 {
        nodec[i].gateC <--> MyChannel <--> noded.gateC[i];        
    }
    for i=0..n-1{
		nodes[i].gateS[i] <--> MyChannel <--> noded.gateS[i];
    }
    for i=0..n-1,
    	for j=i+1..n-1{
    		nodes[i].gateS[j] <--> MyChannel <--> nodes[j].gateS[i];
    }
}