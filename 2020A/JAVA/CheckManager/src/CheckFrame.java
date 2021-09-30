import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Objects;

public class CheckFrame extends JFrame implements ActionListener {
    String[] check_name = {"operate1","operate2","operate3","operate4","operate5","operate6","operate7","operate8","operate9","operate10","operate11",};
    static boolean isRun = false;

    JComboBox check_box;
    JButton check_button, conn_button, disconn_button;
    JTextField url_text, usr_text;
    JPasswordField passwd_text;
    JTextArea show;
    JScrollPane scrollPane;

    CheckDatabase cd;

    CheckFrame(){
        super("查询器");
        this.setLayout(new BorderLayout());

        JPanel opr = new JPanel(new GridLayout(3,1,3,3));

        JPanel jconn = new JPanel();
        JLabel url_label = new JLabel("数据库url: ");
        jconn.add(url_label);
        url_text = new JTextField("localhost:3306/stu",10);
        jconn.add(url_text);
        JLabel usr_label = new JLabel("用户名: ");
        jconn.add(usr_label);
        usr_text = new JTextField(5);
        jconn.add(usr_text);
        JLabel passwd_label = new JLabel("密码: ");
        jconn.add(passwd_label);
        passwd_text = new JPasswordField(5);
        jconn.add(passwd_text);

        JPanel jbtn = new JPanel();
        conn_button = new JButton("连接");
        conn_button.addActionListener(this);
        disconn_button = new JButton("断开");
        disconn_button.addActionListener(this);
        jbtn.add(conn_button);
        jbtn.add(disconn_button);

        JPanel jcheck = new JPanel();
        JLabel label = new JLabel("请选择需要的查询", JLabel.CENTER);
        jcheck.add(label);
        check_box = new JComboBox(check_name);
        jcheck.add(check_box);
        check_button = new JButton("查询");
        check_button.addActionListener(this);
        jcheck.add(check_button);

        opr.add(jconn);
        opr.add(jbtn);
        opr.add(jcheck);
        this.add(opr, BorderLayout.NORTH);

        show = new JTextArea();
        show.setEditable(false);
        scrollPane = new JScrollPane(show);
        this.add(scrollPane, BorderLayout.CENTER);

        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == conn_button){
            if(!isRun) {
                String pwd = new String(passwd_text.getPassword());
                cd = new CheckDatabase(url_text.getText(), usr_text.getText(), pwd, show, scrollPane);
            } else {
                show.setText("");
                scrollPane.validate();
                show.setText("请勿重复连接数据库！");
                scrollPane.validate();
            }
        }
        if(e.getSource() == disconn_button){
            if(isRun) {
                cd.disconnect();
            } else {
                show.setText("");
                scrollPane.validate();
                show.setText("数据库未连接！");
                scrollPane.validate();
            }
        }
        if(e.getSource() == check_button){
            if(!isRun){
                show.setText("");
                scrollPane.validate();
                show.setText("数据库未连接！");
                scrollPane.validate();
                return;
            }
            String operate = Objects.requireNonNull(check_box.getSelectedItem()).toString().trim();
            switch (operate){
                case "operate1":
                    cd.check1();
                    break;
                case "operate2":
                    cd.check2();
                    break;
                case "operate3":
                    cd.check3();
                    break;
                case "operate4":
                    cd.check4();
                    break;
                case "operate5":
                    cd.check5();
                    break;
                case "operate6":
                    cd.check6();
                    break;
                case "operate7":
                    cd.check7();
                    break;
                case "operate8":
                    cd.check8();
                    break;
                case "operate9":
                    cd.check9();
                    break;
                case "operate10":
                    cd.check10();
                    break;
                case "operate11":
                    cd.check11();
                    break;
            }
        }
    }
}
