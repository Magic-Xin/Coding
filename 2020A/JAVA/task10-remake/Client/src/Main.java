public class Main {
    public static void main(String[] args){
        ClientFrame clientFrame =  new ClientFrame();
        SendThread sendThread = new SendThread(clientFrame);
        sendThread.start();
        clientFrame.setClientThread(sendThread);
    }
}
