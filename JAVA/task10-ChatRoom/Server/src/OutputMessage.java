import java.io.*;
import java.util.*;
import java.net.*;

public class OutputMessage {
    List<Socket> all_socket = new ArrayList<>();
    List<User> all_user = new ArrayList<>();
    HashMap<Socket, User> all = new HashMap<>();
    ObjectOutputStream cout;

    OutputMessage() {
    }

    public void addSocket(Socket socket) {
        this.all_socket.add(socket);
    }

    public void popSocket(Socket socket) {
        all_socket.remove(socket);
    }

    public void addUser(User user){
        this.all_user.add(user);
    }

    public void popUser(User user){
        all_user.remove(user);
    }

    public void changeUser(User old_user, User new_user){
        for(int i = 0 ; i < all_user.size() ; i++){
            if(all_user.get(i) == old_user){
                all_user.set(i, new_user);
            }
        }
    }

    public void send_all(User user) {
        System.out.println(user.content);
        for (int i = 0; i < all_socket.size(); i++) {
            Socket temp = all_socket.get(i);
            try {
                cout = new ObjectOutputStream(temp.getOutputStream());
                cout.writeObject(user);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

}
