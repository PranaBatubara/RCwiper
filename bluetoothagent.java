 UUID[] uuidSet = new UUID[1];
 uuidSet[0]=new UUID(0x1105); //OBEX Object Push service

int[] attrIDs =  new int[] {
        0x0100 // Service name
};

LocalDevice localDevice = LocalDevice.getLocalDevice();
DiscoveryAgent agent = localDevice.getDiscoveryAgent();
 agent.searchServices(null,uuidSet,device, new MyDiscoveryListener());
    
    
    try {
        synchronized(lock){
            lock.wait();
        }
    }
    catch (InterruptedException e) {
        e.printStackTrace();
        return;
    }
    

