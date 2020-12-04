import java.io.*;
import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Server implements Runnable{
    private final Socket socket;
    private final UserThread ut;
    private ObjectInputStream ois;

    private boolean isRun = true;

    private String id;

    Server(Socket socket, UserThread ut) {
        this.socket = socket;
        this.ut = ut;
    }

    @Override
    public void run() {
        try {
            System.out.println("Client "+socket.getInetAddress().getHostAddress()+" has connected!");
            while (isRun){
                ois = new ObjectInputStream(socket.getInputStream());
                User user = (User) ois.readObject();
                int status = user.getStatus();
                switch (status){
                    case 0:
                        this.id = user.getId();
                        ut.addUser(socket, id);
                        ut.sendAll(user);
                        break;
                    case 1:
                        String to_whom = user.getTo_whom();
                        if(to_whom.equals("ALL")){
                            ut.sendAll(user);
                        } else {
                            if(!ut.sendOne(user)){
                                user.setTo_whom(user.getId());
                                String str = "Not found the user!\n";
                                byte[] bytes = str.getBytes(StandardCharsets.UTF_8);
                                user.setContent(Base64.getEncoder().encodeToString(bytes));
                                ut.sendOne(user);
                            }
                        }
                        break;
                    case 2:
                        String new_id = user.getId();
                        if(!id.equals(new_id)){
                            this.id = new_id;
                            ut.updateUser(socket, id);
                            ut.sendAll(user);
                        }
                        break;
                    case 3:
                        ut.sendAll(user);
                        ut.removeUser(socket);
                        this.isRun = false;
                        System.out.println("Client "+socket.getInetAddress().getHostAddress()+" has disconnected!");
                        break;
                }
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
