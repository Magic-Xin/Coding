import java.net.*;

public class MainThread implements Runnable {
    @Override
    public void run() {
        try {
            ServerSocket ss = new ServerSocket(8765);
            Socket socket = null;
            OutputMessage om = new OutputMessage();
            System.out.println("Server start!");
            while ((socket = ss.accept()) != null) {
                ServerThread t1 = new ServerThread(socket, om);
                t1.start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
