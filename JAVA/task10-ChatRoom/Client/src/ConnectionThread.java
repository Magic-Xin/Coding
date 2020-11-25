import javax.swing.*;
import java.net.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
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
                cin = new BufferedReader(new InputStreamReader(socket.getInputStream(), StandardCharsets.UTF_8));
                cout = new PrintWriter(new OutputStreamWriter(socket.getOutputStream(), StandardCharsets.UTF_8));
                String str;
                send_text(cnt);
                while ((str = cin.readLine()) != null) {
                    if (!isRun) {
                        break;
                    }
                    byte[] decoded = Base64.getDecoder().decode(str);
                    String deStr = new String(decoded, StandardCharsets.UTF_8);
                    show.append(deStr);
                    show.setCaretPosition(show.getText().length());
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
                show.setCaretPosition(show.getText().length());
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

    public void disconnect(String str) {
        if (isRun) {
            send_text(str);
            try {
                sleep(500);
            } catch (Exception e) {
                e.printStackTrace();
            }
            cout.write(null + "\n");
            cout.flush();
            isRun = false;
        }
    }

    public void send_text(String str) {
        try {
            byte[] bytes = str.getBytes(StandardCharsets.UTF_8);
            String encoded = Base64.getEncoder().encodeToString(bytes);
            if (cout != null) {
                cout.write(encoded + "\n");
                cout.flush();
            } else {
                show.append("Connection lost!\n");
                show.setCaretPosition(show.getText().length());
                scrollPane.validate();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
