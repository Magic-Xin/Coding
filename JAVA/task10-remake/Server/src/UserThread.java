import java.net.*;
import java.util.*;
import java.io.*;

public class UserThread {
    private final HashMap<Socket, String> all_client;

    UserThread(){
        all_client = new HashMap<>();
    }

    public void addUser(Socket socket, String id){
        this.all_client.put(socket, id);
    }

    public void removeUser(Socket socket){
        this.all_client.remove(socket);
    }

    public void updateUser(Socket socket, String id){
        this.all_client.replace(socket, id);
    }

    public void sendAll(User user){
        Set<Socket> all_socket = all_client.keySet();
        Iterator<Socket> it = all_socket.iterator();
        while(it.hasNext()){
            Socket socket = it.next();
            if(all_client.get(socket) != null) {
                try {
                    ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
                    oos.writeObject(user);
                    oos.flush();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public boolean sendOne(User user){
        String from_id = user.getId();
        String to_whom = user.getTo_whom();
        int send = 0;
        Set<Socket> all_socket = all_client.keySet();
        Iterator<Socket> it = all_socket.iterator();
        while(it.hasNext()){
            Socket socket = it.next();
            String id = all_client.get(socket);
            if(id.equals(to_whom) || id.equals(from_id)){
                try{
                    ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
                    oos.writeObject(user);
                    oos.flush();
                } catch (Exception e){
                    e.printStackTrace();
                }
                send++;
            }
        }
        if(send == 2){
            return true;
        }
        return false;
    }
}
