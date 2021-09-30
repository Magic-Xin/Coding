import java.net.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ReadThread extends Thread{
    private Socket socket;
    private SendThread sendThread;
    private ClientFrame clientFrame;

    public ReadThread(Socket socket, ClientFrame clientFrame, SendThread sendThread){
        this.socket = socket;
        this.clientFrame = clientFrame;
        this.sendThread = sendThread;
    }

    public void run(){
        try {
            while (sendThread.isRun()) {
                ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
                User temp = (User)ois.readObject();
                String str = temp.getContent();
                byte[] decoded = Base64.getDecoder().decode(str);
                String destr = new String(decoded, StandardCharsets.UTF_8);
                clientFrame.newText(destr);
            }
            socket.close();
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
