import java.io.*;
import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class SendThread extends Thread{
    private Socket socket;
    private boolean run = false;

    ClientFrame clientFrame;
    ReadThread readThread;
    User user;

    SendThread(ClientFrame clientFrame){
        this.clientFrame = clientFrame;
    }

    public void run(String ip, String nickname) {
        try{
            socket = new Socket(ip, 8765);
            String content = nickname + " has connected to the server!\n";
            this.user = new User(nickname);
            readThread = new ReadThread(socket, clientFrame,this);
            readThread.start();
            send("ALL",content,0);
        } catch (Exception e){
            e.printStackTrace();
        }
    }

    public void send(String to_whom, String str, int status){
        byte[] bytes = str.getBytes(StandardCharsets.UTF_8);
        this.user.setTo_whom(to_whom);
        this.user.setContent(Base64.getEncoder().encodeToString(bytes));
        this.user.setStatus(status);
        try{
            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            oos.writeObject(this.user);
            oos.flush();
        } catch (Exception e){
            e.printStackTrace();
        }
    }

    public void disconnect(String str){
        send("ALL", str, 3);
        try {
            sleep(500);
            this.setRun(false);
        } catch (Exception e){
            e.printStackTrace();
        }
    }

    public void changeUser(String str, String nickname){
        this.user.setId(nickname);
        send("ALL",str,2);
    }

    public boolean isRun(){
        return this.run;
    }

    public void setRun(boolean run){
        this.run = run;
    }
}
