import java.net.*;

public class Main {
    public static void main(String[] args){
        UserThread ut = new UserThread();
        try {
            ServerSocket ss = new ServerSocket(8765);
            Socket socket;
            System.out.println("Server start!");
            while ((socket = ss.accept()) != null) {
                Runnable runnable = new Server(socket, ut);
                Thread thread = new Thread(runnable);
                thread.start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
