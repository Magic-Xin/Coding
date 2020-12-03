import java.net.*;
import java.io.*;

public class UserThread extends Thread {
    Socket socket;
    ObjectInputStream oi;
    OutputMessage om;
    User user = null;

    UserThread(Socket socket, OutputMessage om){
        this.socket = socket;
        this.om = om;
    }

    public void run() {
        try {
            InputStream is = socket.getInputStream();
            oi = new ObjectInputStream(is);
            Object obj = oi.readObject();
            if (obj != null) {
                if(user == null){
                    user = (User)obj;
                    om.addUser(user);
                }
                else{
                    om.changeUser(user, (User)obj);
                    user = (User)obj;
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
