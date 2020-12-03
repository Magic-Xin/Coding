import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class ClientFrame extends JFrame implements ActionListener {
    JLabel ip, name;
    JTextField ip_t, name_t, input_t;
    JButton connect, disconnect, set, send;
    JTextArea show;
    JScrollPane scrollPane;

    String nickname = "Anymouse";
    String server_ip = "127.0.0.1";

    SendThread ct;

    ClientFrame() {
        this.setLayout(new BorderLayout());

        JPanel settings = new JPanel();
        settings.setLayout(new GridLayout(2, 1, 3, 3));

        JPanel ip_p = new JPanel();
        ip = new JLabel("Server IP: ");
        ip_t = new JTextField(20);
        ip_t.setText("127.0.0.1");
        connect = new JButton("Connect");
        connect.addActionListener(this);
        disconnect = new JButton("Disconnect");
        disconnect.addActionListener(this);
        ip_p.add(ip);
        ip_p.add(ip_t);
        ip_p.add(connect);
        ip_p.add(disconnect);
        settings.add(ip_p);

        JPanel name_p = new JPanel();
        name = new JLabel("Nickname: ");
        name_t = new JTextField(20);
        name_t.setText("Anymouse");
        set = new JButton("Set nickname");
        set.addActionListener(this);
        name_p.add(name);
        name_p.add(name_t);
        name_p.add(set);
        settings.add(name_p);

        show = new JTextArea();
        show.setEditable(false);
        scrollPane = new JScrollPane(show);

        JPanel send_p = new JPanel();
        input_t = new JTextField(20);
        input_t.addKeyListener(new KeyListener() {
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    send_text();
                }
            }

            public void keyReleased(KeyEvent e) {
            }

            public void keyTyped(KeyEvent e) {
            }
        });
        send = new JButton("Send");
        send.addActionListener(this);
        send_p.add(input_t);
        send_p.add(send);

        this.add(settings, BorderLayout.NORTH);
        this.add(scrollPane, BorderLayout.CENTER);
        this.add(send_p, BorderLayout.SOUTH);

        setVisible(true);
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == connect) {
            if (!SendThread.isRun) {
                this.server_ip = ip_t.getText().trim();
                ct = new SendThread(show, scrollPane, nickname);
                ct.connect(this.server_ip);
                SendThread.isRun = true;
            }
        }
        if (e.getSource() == disconnect) {
            String temp = this.nickname + " has disconnected to the server!\n";
            ct.disconnect(temp);
            ct = null;
        }
        if (e.getSource() == set) {
            if (SendThread.isRun) {
                String temp = this.nickname + " has changed nickname to: " + name_t.getText() + "\n";
                this.nickname = name_t.getText();
                ct.change_user(temp, nickname);
            } else {
                this.nickname = name_t.getText();
                show.append("Changed to: " + this.nickname + "\n");
                show.setCaretPosition(show.getText().length());
                scrollPane.validate();
            }
        }
        if (e.getSource() == send) {
            send_text();
        }
    }

    private void send_text() {
        if (input_t.getText().length() < 1) {
            return;
        }
        if (SendThread.isRun) {
            String str;
            str = nickname + ": " + input_t.getText() + "\n";
            ct.send_text(str,1);
        } else {
            show.append("Please connect to the server!\n");
            show.setCaretPosition(show.getText().length());
            scrollPane.validate();
        }
        input_t.setText("");
    }
}
