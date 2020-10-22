import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class CalForm extends JFrame implements ActionListener {
    JPanel num = new JPanel(new GridLayout(4,3,3,3));
    JPanel opr = new JPanel(new GridLayout(4,2,3,3));
    JTextField t = new JTextField("0");
    JButton num_btn[], opr_btn[];

    double result;
    int oprator = 0;

    String num_str[] = {"7", "8", "9", "4", "5", "6", "1", "2", "3", "0", ".", "AC"};
    String opr_str[] = {"+", "-", "x", "/", "%", "=", "C"};

    CalForm(){
        super("Calculator");
        setLayout(new BorderLayout());
        num_btn = new JButton[num_str.length];
        opr_btn = new JButton[opr_str.length];

        for(int i = 0 ; i < num_str.length ; i++){
            num_btn[i] = new JButton(num_str[i]);
            num_btn[i].addActionListener(this);
            num.add(num_btn[i]);
        }
        for(int i = 0 ; i < opr_str.length ; i++){
            opr_btn[i] = new JButton(opr_str[i]);
            opr_btn[i].addActionListener(this);
            opr.add(opr_btn[i]);
        }

        getContentPane().add(t, BorderLayout.NORTH);
        getContentPane().add(num, BorderLayout.WEST);
        getContentPane().add(opr, BorderLayout.EAST);

        setVisible(true);
        setSize(400, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        result = 0;
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource() == num_btn[0]){
            String temp = t.getText();
            if(temp.equals("0")){
                temp = "7";
            }
            else{
                temp += "7";
            }
            t.setText(temp);
        }
        if(e.getSource() == num_btn[1]){
            String temp = t.getText();
            if(temp.equals("0")){
                temp = "8";
            }
            else{
                temp += "8";
            }
            t.setText(temp);
        }
        if(e.getSource() == num_btn[2]){
            String temp = t.getText();
            if(temp.equals("0")){
                temp = "9";
            }
            else{
                temp += "9";
            }
            t.setText(temp);
        }
        if(e.getSource() == num_btn[3]){
            String temp = t.getText();
            if(temp.equals("0")){
                temp = "4";
            }
            else{
                temp += "4";
            }
            t.setText(temp);
        }
        if(e.getSource() == num_btn[4]){
            String temp = t.getText();
            if(temp.equals("0")){
                temp = "5";
            }
            else{
                temp += "5";
            }
            t.setText(temp);
        }
        if(e.getSource() == num_btn[5]){
            String temp = t.getText();
            if(temp.equals("0")){
                temp = "6";
            }
            else{
                temp += "6";
            }
            t.setText(temp);
        }
        if(e.getSource() == num_btn[6]){
            String temp = t.getText();
            if(temp.equals("0")){
                temp = "1";
            }
            else{
                temp += "1";
            }
            t.setText(temp);
        }
        if(e.getSource() == num_btn[7]){
            String temp = t.getText();
            if(temp.equals("0")){
                temp = "2";
            }
            else{
                temp += "2";
            }
            t.setText(temp);
        }
        if(e.getSource() == num_btn[8]){
            String temp = t.getText();
            if(temp.equals("0")){
                temp = "3";
            }
            else{
                temp += "3";
            }
            t.setText(temp);
        }
        if(e.getSource() == num_btn[9]){
            String temp = t.getText();
            if(temp.equals("0")){
                temp = "0";
            }
            else{
                temp += "0";
            }
            t.setText(temp);
        }
        if(e.getSource() == num_btn[10]){
            String temp = t.getText();
            temp += ".";
            t.setText(temp);
        }
        if(e.getSource() == num_btn[11]){
            t.setText("0");
        }
        if(e.getSource() == opr_btn[0]){
            oprate();
            oprator = 1;
            t.setText("0");
        }
        if(e.getSource() == opr_btn[1]){
            oprate();
            oprator = 2;
            t.setText("0");
        }
        if(e.getSource() == opr_btn[2]){
            oprate();
            oprator = 3;
            t.setText("0");
        }
        if(e.getSource() == opr_btn[3]){
            oprate();
            oprator = 4;
            t.setText("0");
        }
        if(e.getSource() == opr_btn[4]){
            oprate();
            oprator = 5;
            t.setText("0");
        }
        if(e.getSource() == opr_btn[5]){
            double temp = Double.parseDouble(t.getText());
            if(oprator == 0) return;
            oprate();
            String res = "";
            res += result;
            oprator = 0;
            t.setText(res);
        }
        if(e.getSource() == opr_btn[6]){
            result = 0;
            oprator = 0;
            t.setText("0");
        }
    }

    private void oprate(){
        double temp = Double.parseDouble(t.getText());
        if(oprator == 0){
            result = temp;
        }
        if(oprator == 1){
            result += temp;
        }
        if(oprator == 2){
            result -= temp;
        }
        if(oprator == 3){
            result *= temp;
        }
        if(oprator == 4){
            if(temp == 0){
                t.setText("0");
                result = 0;
                oprator = 0;
                return;
            }
            result /= temp;
        }
        if(oprator == 5){
            if(temp == 0){
                t.setText("0");
                result = 0;
                oprator = 0;
                return;
            }
            result %= temp;
        }
        return;
    }
}
