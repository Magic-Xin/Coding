import java.util.*;

public class OutputMessage {
    Vector<ServerThread> all_ServerThread = new Vector<ServerThread>();

    OutputMessage() {
    }

    public boolean addThread(ServerThread t) {
        if (this.all_ServerThread.add(t)) {
            return true;
        }
        return false;
    }

    public void popThread(ServerThread t) {
        all_ServerThread.remove(t);
        System.out.println("Thread deleted!");
    }

    public void send_all(String str) {
        for (int i = 0; i < all_ServerThread.size(); i++) {
            ServerThread temp = all_ServerThread.get(i);
            temp.send(str);
        }
    }

}
