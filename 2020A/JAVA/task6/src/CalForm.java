import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class CalForm extends JFrame implements ActionListener {
    JPanel num = new JPanel(new GridLayout(4, 3, 3, 3));
    JPanel opr = new JPanel(new GridLayout(4, 3, 3, 3));
    JPanel Text = new JPanel();
    JPanel Cal = new JPanel(new GridLayout(1, 2, 3, 3));

    JTextField t = new JTextField("0");
    JButton num_btn[], opr_btn[];

    double result;
    int oprator = 0;

    String num_str[] = { "7", "8", "9", "4", "5", "6", "1", "2", "3", "0", "+/-", "." };
    String opr_str[] = { "/", "sqrt", "ln", "*", "sin", "<-", "-", "cos", "CE", "+", "y^x", "=" };

    CalForm() {
        super("Calculator");
        this.setLayout(new BorderLayout());
        num_btn = new JButton[num_str.length];
        opr_btn = new JButton[opr_str.length];

        for (int i = 0; i < num_str.length; i++) {
            num_btn[i] = new JButton(num_str[i]);
            num_btn[i].addActionListener(this);
            num.add(num_btn[i]);
        }
        for (int i = 0; i < opr_str.length; i++) {
            opr_btn[i] = new JButton(opr_str[i]);
            opr_btn[i].addActionListener(this);
            opr.add(opr_btn[i]);
        }

        Cal.add(num);
        Cal.add(opr);
        t.setPreferredSize(new Dimension(300, 30));
        Text.add(t);

        this.add(Text, BorderLayout.NORTH);
        this.add(Cal, BorderLayout.CENTER);

        setVisible(true);
        setSize(400, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        result = 0;
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == num_btn[0]) {
            String temp = t.getText();
            if (temp.equals("0")) {
                temp = "7";
            } else {
                temp += "7";
            }
            t.setText(temp);
        }
        if (e.getSource() == num_btn[1]) {
            String temp = t.getText();
            if (temp.equals("0")) {
                temp = "8";
            } else {
                temp += "8";
            }
            t.setText(temp);
        }
        if (e.getSource() == num_btn[2]) {
            String temp = t.getText();
            if (temp.equals("0")) {
                temp = "9";
            } else {
                temp += "9";
            }
            t.setText(temp);
        }
        if (e.getSource() == num_btn[3]) {
            String temp = t.getText();
            if (temp.equals("0")) {
                temp = "4";
            } else {
                temp += "4";
            }
            t.setText(temp);
        }
        if (e.getSource() == num_btn[4]) {
            String temp = t.getText();
            if (temp.equals("0")) {
                temp = "5";
            } else {
                temp += "5";
            }
            t.setText(temp);
        }
        if (e.getSource() == num_btn[5]) {
            String temp = t.getText();
            if (temp.equals("0")) {
                temp = "6";
            } else {
                temp += "6";
            }
            t.setText(temp);
        }
        if (e.getSource() == num_btn[6]) {
            String temp = t.getText();
            if (temp.equals("0")) {
                temp = "1";
            } else {
                temp += "1";
            }
            t.setText(temp);
        }
        if (e.getSource() == num_btn[7]) {
            String temp = t.getText();
            if (temp.equals("0")) {
                temp = "2";
            } else {
                temp += "2";
            }
            t.setText(temp);
        }
        if (e.getSource() == num_btn[8]) {
            String temp = t.getText();
            if (temp.equals("0")) {
                temp = "3";
            } else {
                temp += "3";
            }
            t.setText(temp);
        }
        if (e.getSource() == num_btn[9]) {
            String temp = t.getText();
            if (temp.equals("0")) {
                temp = "0";
            } else {
                temp += "0";
            }
            t.setText(temp);
        }
        if (e.getSource() == num_btn[10]) {
            StringBuffer temp = new StringBuffer(t.getText());
            if (temp.charAt(0) == '0') {
                return;
            }
            if (temp.charAt(0) == '-') {
                temp.delete(0, 1);
            } else {
                temp.insert(0, '-');
            }
            String print = temp.toString();
            t.setText(print);
        }
        if (e.getSource() == num_btn[11]) {
            String temp = t.getText();
            temp += ".";
            t.setText(temp);
        }

        if (e.getSource() == opr_btn[0]) {
            oprate();
            oprator = 4;
            t.setText("0");
        }
        if (e.getSource() == opr_btn[1]) {
            result = Double.parseDouble(t.getText());
            if (result <= 0) {
                t.setText("0");
                return;
            }
            oprator = 5;
            oprate();
            oprator = 0;
            String res = "";
            res += result;
            t.setText(res);
        }
        if (e.getSource() == opr_btn[2]) {
            result = Double.parseDouble(t.getText());
            if (result <= 0) {
                t.setText("0");
                return;
            }
            oprator = 6;
            oprate();
            oprator = 0;
            String res = "";
            res += result;
            t.setText(res);
        }
        if (e.getSource() == opr_btn[3]) {
            oprate();
            oprator = 3;
            t.setText("0");
        }
        if (e.getSource() == opr_btn[4]) {
            result = Double.parseDouble(t.getText());
            oprator = 7;
            oprate();
            oprator = 0;
            String res = "";
            res += result;
            t.setText(res);
        }
        if (e.getSource() == opr_btn[5]) {
            String temp = t.getText();
            if (temp.length() <= 1) {
                t.setText("0");
                return;
            }
            temp = temp.substring(0, temp.length() - 1);
            t.setText(temp);
        }
        if (e.getSource() == opr_btn[6]) {
            oprate();
            oprator = 2;
            t.setText("0");
        }
        if (e.getSource() == opr_btn[7]) {
            result = Double.parseDouble(t.getText());
            oprator = 8;
            oprate();
            oprator = 0;
            String res = "";
            res += result;
            t.setText(res);
        }
        if (e.getSource() == opr_btn[8]) {
            result = 0;
            oprator = 0;
            t.setText("0");
        }
        if (e.getSource() == opr_btn[9]) {
            oprate();
            oprator = 1;
            t.setText("0");
        }
        if (e.getSource() == opr_btn[10]) {
            oprate();
            oprator = 9;
            t.setText("0");
        }
        if (e.getSource() == opr_btn[11]) {
            double temp = Double.parseDouble(t.getText());
            if (oprator == 0)
                return;
            oprate();
            String res = "";
            res += result;
            oprator = 0;
            t.setText(res);
        }
    }

    private void oprate() {
        double temp = Double.parseDouble(t.getText());
        if (oprator == 0) {
            result = temp;
        }
        if (oprator == 1) {
            result += temp;
        }
        if (oprator == 2) {
            result -= temp;
        }
        if (oprator == 3) {
            result *= temp;
        }
        if (oprator == 4) {
            if (temp == 0) {
                t.setText("0");
                result = 0;
                oprator = 0;
                return;
            }
            result /= temp;
        }
        if (oprator == 5) {
            result = Math.sqrt(result);
        }
        if (oprator == 6) {
            result = Math.log(result);
        }
        if (oprator == 7) {
            result = Math.sin(result);
        }
        if (oprator == 8) {
            result = Math.cos(result);
        }
        if (oprator == 9) {
            result = Math.pow(result, temp);
        }
        return;
    }
}
