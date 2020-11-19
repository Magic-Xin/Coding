import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class WriteFrame extends JFrame implements ActionListener {

    JLabel num, name, sex, clas, cn, math, eng, pe, status;
    JTextField num_t, name_t, sex_t, clas_t, cn_t, math_t, eng_t, pe_t;
    JButton write, clear;

    String dir = "Students.txt";
    File fl = new File(dir);
    FileWriter fw;

    public void createFrame() {
        this.setLayout(new GridLayout(3, 1, 3, 3));

        JPanel input = new JPanel(new FlowLayout());
        num = new JLabel("学号：");
        name = new JLabel("姓名：");
        sex = new JLabel("性别：");
        clas = new JLabel("班级：");
        cn = new JLabel("语文：");
        math = new JLabel("数学：");
        eng = new JLabel("英语：");
        pe = new JLabel("体育：");

        num_t = new JTextField(5);
        name_t = new JTextField(5);
        sex_t = new JTextField(5);
        clas_t = new JTextField(5);
        cn_t = new JTextField(5);
        math_t = new JTextField(5);
        eng_t = new JTextField(5);
        pe_t = new JTextField(5);

        input.add(num);
        input.add(num_t);
        input.add(name);
        input.add(name_t);
        input.add(sex);
        input.add(sex_t);
        input.add(clas);
        input.add(clas_t);
        input.add(cn);
        input.add(cn_t);
        input.add(math);
        input.add(math_t);
        input.add(eng);
        input.add(eng_t);
        input.add(pe);
        input.add(pe_t);
        this.add(input);

        status = new JLabel("请录入数据");
        this.add(status);

        JPanel Buttons = new JPanel(new FlowLayout());
        write = new JButton("写入");
        write.addActionListener(this);
        clear = new JButton("清除");
        clear.addActionListener(this);
        Buttons.add(write);
        Buttons.add(clear);
        this.add(Buttons);

        setVisible(true);
        setSize(500, 400);
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == write) {
            WriteIn();
        }
        if (e.getSource() == clear) {
            Clear_Textfield();
        }
    }

    void WriteIn() {
        if (num_t.getText().length() < 1 || name_t.getText().length() < 1 || sex_t.getText().length() < 1
                || clas_t.getText().length() < 1 || cn_t.getText().length() < 1 || math_t.getText().length() < 1
                || eng_t.getText().length() < 1 || pe_t.getText().length() < 1) {
            status.setText("数据不完整，请重新输入");
            return;
        }
        try {
            if (fl.exists()) {
                fw = new FileWriter(fl, true);
            } else {
                fl.createNewFile();
                fw = new FileWriter(fl);
            }
            fw.write(num_t.getText() + "," + name_t.getText() + "," + sex_t.getText() + "," + clas_t.getText() + ","
                    + cn_t.getText() + "," + math_t.getText() + "," + eng_t.getText() + "," + pe_t.getText() + "\n");
            fw.flush();
            fw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        status.setText("写入成功");
        Clear_Textfield();
    }

    void Clear_Textfield() {
        num_t.setText("");
        name_t.setText("");
        sex_t.setText("");
        clas_t.setText("");
        cn_t.setText("");
        math_t.setText("");
        eng_t.setText("");
        pe_t.setText("");
    }
}
