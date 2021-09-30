import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ArgsFrame extends JFrame implements ActionListener, Runnable {
    int low, high;

    JTextField low_text, high_text;
    JButton run;

    CheckDatabase cd;

    ArgsFrame(CheckDatabase cd){
        this.cd = cd;
    }

    public void run(){
        this.setLayout(new GridLayout(2,1,3,3));

        JPanel opr = new JPanel();
        JLabel low_label = new JLabel("Low: ");
        low_text = new JTextField(5);
        JLabel high_label = new JLabel("High: ");
        high_text = new JTextField(5);
        opr.add(low_label);
        opr.add(low_text);
        opr.add(high_label);
        opr.add(high_text);

        JPanel btn = new JPanel();
        run = new JButton("确定");
        run.addActionListener(this);
        btn.add(run);

        this.add(opr);
        this.add(btn);

        setVisible(true);
        setSize(300, 100);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == run) {
            try {
                low = Integer.parseInt(low_text.getText());
                high = Integer.parseInt(high_text.getText());
                String sql = "call getinfo" + "(" + low + "," + high + ")";
                cd.resultSet = cd.statement.executeQuery(sql);
                while (cd.resultSet.next()) {
                    String name = cd.resultSet.getString("Sname");
                    String dept = cd.resultSet.getString("Sdept");
                    int grade = cd.resultSet.getInt("Grade");
                    String res = name + " " + dept + " " + grade + "\n";
                    cd.showText(res);
                }
            } catch (Exception err) {
                err.printStackTrace();
                cd.showText("操作失败！");
            }
            this.dispose();
        }
    }
}

