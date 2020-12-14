import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ClientFrame extends JFrame implements ActionListener{
    private JLabel ip, name, whom, content;
    private JTextField ip_t, name_t, input_t, whom_t;
    private JButton connect, disconnect, set, send;
    private JTextArea show;
    private JScrollPane scrollPane;

    private String nickname = "Anymouse";
    private String server_ip = "127.0.0.1";

    SendThread sendThread;

    public ClientFrame() {
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
        whom = new JLabel("To whom: ");
        whom_t = new JTextField("ALL",5);
        content = new JLabel("Content: ");
        input_t = new JTextField(20);
        input_t.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}

            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    send_text();
                }
            }

            @Override
            public void keyReleased(KeyEvent e) {}
        });
        send = new JButton("Send");
        send.addActionListener(this);
        send_p.add(whom);
        send_p.add(whom_t);
        send_p.add(content);
        send_p.add(input_t);
        send_p.add(send);

        this.add(settings, BorderLayout.NORTH);
        this.add(scrollPane, BorderLayout.CENTER);
        this.add(send_p, BorderLayout.SOUTH);

        setVisible(true);
        setSize(600, 400);
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e)
            {
                if(sendThread.isRun()) {
                    String str = nickname + " has disconnected to the server!\n";
                    sendThread.disconnect(str);
                }
                System.exit(0);
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == connect) {
            if (!sendThread.isRun()) {
                this.server_ip = ip_t.getText().trim();
                sendThread.setRun(true);
                sendThread.run(this.getIp(), this.getNickname());
            }
        }
        if (e.getSource() == disconnect) {
            String str = this.nickname + " has disconnected to the server!\n";
            sendThread.disconnect(str);
        }
        if (e.getSource() == set) {
            if (sendThread.isRun()) {
                String str = this.nickname + " has changed nickname to: " + name_t.getText() + "\n";
                this.nickname = name_t.getText();
                sendThread.changeUser(str, nickname);
            } else {
                this.nickname = name_t.getText();
                this.newText("Changed to: " + this.nickname + "\n");
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
        if (sendThread.isRun()) {
            String to_whom = whom_t.getText().trim();
            String str = "From "+nickname+" To "+to_whom+ ": " + input_t.getText() + "\n";
            sendThread.send(to_whom, str,1);
        } else {
            this.newText("Please connect to the server!\n");
        }
        input_t.setText("");
    }

    public void setClientThread(SendThread sendThread){
        this.sendThread = sendThread;
    }

    public String getIp() {
        return this.server_ip;
    }

    public String getNickname(){
        return this.nickname;
    }

    public void newText(String str){
        show.append(str);
        show.setCaretPosition(show.getText().length());
        scrollPane.validate();
    }
}
