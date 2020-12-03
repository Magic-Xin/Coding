import javax.swing.*;
import java.net.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.concurrent.*;

public class SendThread extends Thread {
    Socket socket;
    ObjectInputStream cin;
    ObjectOutputStream cout;
    String ip;
    static boolean isRun = false;

    User user;
    ExecutorService es;

    JTextArea show;
    JScrollPane scrollPane;

    SendThread(JTextArea show, JScrollPane scrollPane, String nickname) {
        this.show = show;
        this.scrollPane = scrollPane;
        user = new User(nickname);
        es = Executors.newSingleThreadExecutor();
    }

    public void run() {
        try {
            socket = new Socket(ip, 8765);
            cout = new ObjectOutputStream(socket.getOutputStream());
            cin = new ObjectInputStream(socket.getInputStream());
            es.execute(new ReadThread(cin));
            String str = user.id + " has connected to the server!\n";
            send_text(str, 0);
        } catch (Exception e) {
            e.printStackTrace();
            show.append("Connection failed!\n");
            show.setCaretPosition(show.getText().length());
            scrollPane.validate();
            isRun = false;
        }
    }

    public void connect(String ip) {
        this.ip = ip;
        isRun = true;
        this.start();
    }

    public void disconnect(String str) {
        if (isRun) {
            send_text(str, 3);
            try {
                sleep(500);
            } catch (Exception e) {
                e.printStackTrace();
            }
            isRun = false;
        }
    }

    public void send_text(String str, int status) {
        try {
            byte[] bytes = str.getBytes(StandardCharsets.UTF_8);
            user.content = Base64.getEncoder().encodeToString(bytes);
            user.status = status;
            System.out.println(user.status);
            cout.writeObject(user);
        } catch (Exception e) {
            e.printStackTrace();
            show.append("Connection lost!\n");
            show.setCaretPosition(show.getText().length());
            scrollPane.validate();
        }
    }

    public void change_user(String str, String nickname) {
        user.id = nickname;
        send_text(str, 2);
    }
}