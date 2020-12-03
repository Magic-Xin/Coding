import java.io.*;
import java.net.*;

public class ServerThread extends Thread {
    Socket socket;
    ObjectInputStream ois;
    OutputMessage om;

    User user = null;

    boolean isRun = false;

    ServerThread(Socket socket, OutputMessage om) {
        this.socket = socket;
        this.om = om;
        this.isRun = true;
    }

    public void run() {
        try {
            System.out.println("客户端：" + socket.getInetAddress().getHostAddress() + "已连接！");
            ois = new ObjectInputStream(socket.getInputStream());
            while (isRun) {
                User temp = (User)ois.readObject();
                switch (temp.status){
                    case 0:
                        this.user = temp;
                        om.addUser(this.user);
                        break;
                    case 1:
                        this.user = temp;
                        break;
                    case 2:
                        om.changeUser(this.user, temp);
                        this.user = temp;
                        break;
                    case 3:
                        om.send_all(temp);
                        close();
                        return;
                }
                om.send_all(user);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void close() {
        try {
            ois.close();
            socket.close();
            om.popSocket(socket);
            om.popUser(user);
            this.isRun = false;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
