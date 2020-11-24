import java.io.*;
import java.net.*;

public class ServerThread extends Thread {
    Socket socket;
    BufferedReader cin;
    PrintWriter cout;
    OutputMessage om;

    ServerThread(Socket socket, OutputMessage om) {
        this.socket = socket;
        this.om = om;
    }

    public void send(String str) {
        try {
            cout = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
            cout.println(str);
            cout.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void run() {
        try {
            String input;
            cin = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            while ((input = cin.readLine()) != null) {
                om.send_all(input);
            }
            close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void close() {
        try {
            cin.close();
            cout.close();
            socket.close();
            om.popThread(this);
            System.out.println("Client closed!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
