import java.net.*;

public class MainThread implements Runnable {
    @Override
    public void run() {
        try {
            ServerSocket ss = new ServerSocket(8765);
            Socket socket = null;
            OutputMessage om = new OutputMessage();
            System.out.println("Server start!");
            while (true) {
                socket = ss.accept();
                ServerThread t = new ServerThread(socket, om);
                t.start();
                if (om.addThread(t)) {
                    System.out.println("Client add succeed!");
                } else {
                    System.out.println("Client add Failed!");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
