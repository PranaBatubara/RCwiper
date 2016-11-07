@Override
   public void serviceSearchCompleted(int arg0, int arg1) {
       synchronized (lock) {
           lock.notify();
       }
   }

   @Override
  public void servicesDiscovered(int arg0, ServiceRecord[] services) {
       for (int i = 0; i < services.length; i++) {
           String url = services[i].getConnectionURL(ServiceRecord.NOAUTHENTICATE_NOENCRYPT, false);
           if (url == null) {
               continue;
           }
           
           DataElement serviceName = services[i].getAttributeValue(0x0100);
           if (serviceName != null) {
               System.out.println("service " + serviceName.getValue() + " found " + url);
           } else {
               System.out.println("service found " + url);
           }

              if(serviceName.getValue().equals("OBEX Object Push")){
                       sendMessageToDevice(url);                
                   }
       }
       
   }
