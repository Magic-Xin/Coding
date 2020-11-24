import javax.swing.*;
import java.net.*;
import java.io.*;
import java.util.*;

public class ConnectionThread extends Thread {
    Socket socket;
    BufferedReader cin;
    PrintWriter cout;
    String ip, cnt;

    static boolean isRun = false;

    JTextArea show;
    JScrollPane scrollPane;

    ConnectionThread(JTextArea show, JScrollPane scrollPane) {
        this.show = show;
        this.scrollPane = scrollPane;
    }

    public void run() {
        while (isRun) {
            try {
                socket = new Socket(ip, 8765);
                cin = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                cout = new PrintWriter(socket.getOutputStream());
                String str;
                send_text(cnt);
                while ((str = cin.readLine()) != null) {
                    if (!isRun) {
                        break;
                    }
                    byte[] decoded = Base64.getDecoder().decode(str);
                    String deStr = new String(decoded);
                    show.append(deStr);
                    scrollPane.validate();
                }
                cin.close();
                cout.close();
                socket.close();
                cin = null;
                cout = null;
            } catch (Exception e) {
                e.printStackTrace();
                show.append("Connection failed!\n");
                scrollPane.validate();
                isRun = false;
            }
        }
    }

    public void connect(String ip, String str) {
        this.ip = ip;
        this.cnt = str;
        isRun = true;
        this.start();
    }

    public void disconnect(String temp) {
        if (isRun) {
            send_text(temp);
            try {
                sleep(500);
            } catch (Exception e) {
                e.printStackTrace();
            }
            cout.write("exit\n");
            cout.flush();
            isRun = false;
        }
    }

    public void send_text(String str) {
        byte[] bytes = str.getBytes();
        String encoded = Base64.getEncoder().encodeToString(bytes);
        if (cout != null) {
            cout.write(encoded + "\n");
            cout.flush();
        } else {
            show.append("Connection lost!\n");
            scrollPane.validate();
        }
    }
}
