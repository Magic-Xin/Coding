import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class task4 {
    public static void main(String[] args) {
        new StudentForm(); //构造GUI窗体
    }
}

class StudentForm extends Frame implements ActionListener {
    TextField s_num, c_num, name, gender, age, res_t, find_t; //定义输入框
    Label s, c, n, g, a, res, find; //定义标签
    Button writeIn, getS_num, getC_num, getName, getGender, getAge, editAge, getAll; //定义按钮
    List<Student> Students; //使用List存储Student类

    StudentForm() {
        /* 初始化Label */
        s = new Label("学号：");
        c = new Label("班号：");
        n = new Label("姓名：");
        g = new Label("性别：");
        a = new Label("年龄：");
        res = new Label("结果：");
        find = new Label("查找位数");
        /* 初始化Textfield */
        s_num = new TextField(4);
        c_num = new TextField(4);
        name = new TextField(4);
        gender = new TextField(4);
        age = new TextField(4);
        res_t = new TextField(20);
        find_t = new TextField(4);
        /* 初始化Button */
        writeIn = new Button("创建");
        getS_num = new Button("获取学号");
        getC_num = new Button("获取班号");
        getName = new Button("获取姓名");
        getGender = new Button("获取性别");
        getAge = new Button("获取年龄");
        editAge = new Button("修改年龄");
        getAll = new Button("获取全部");

        setLayout(new FlowLayout());
        /*增加布局*/
        add(s);
        add(s_num);
        add(c);
        add(c_num);
        add(n);
        add(name);
        add(g);
        add(gender);
        add(a);
        add(age);
        add(writeIn);
        add(find);
        add(find_t);
        add(getS_num);
        add(getC_num);
        add(getName);
        add(getGender);
        add(getAge);
        add(editAge);
        add(getAll);
        add(res);
        add(res_t);
        /*为Button增加ActionListener监听*/
        writeIn.addActionListener(this);
        getS_num.addActionListener(this);
        getC_num.addActionListener(this);
        getName.addActionListener(this);
        getGender.addActionListener(this);
        getAge.addActionListener(this);
        editAge.addActionListener(this);
        getAll.addActionListener(this);

        setSize(600, 300);
        setVisible(true);

        Students = new ArrayList<Student>();
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == writeIn) { //创建新学生信息
            String ss = s_num.getText();
            String cc = c_num.getText();
            String nn = name.getText();
            String gg = gender.getText();
            int aa = Integer.parseInt(age.getText());
            Student student = new Student(ss, cc, nn, gg, aa);
            Students.add(student);
            res_t.setText("创建成功");
        }
        if (e.getSource() == getS_num) { //获取指定学生学号
            int pos = Integer.parseInt(find_t.getText());
            int check = 1;
            for (Student i : Students) {
                if (check == pos) {
                    res_t.setText(i.get_s_num());
                    break;
                }
                check++;
            }
        }
        if (e.getSource() == getC_num) { //获取指定学生班号
            int pos = Integer.parseInt(find_t.getText());
            int check = 1;
            for (Student i : Students) {
                if (check == pos) {
                    res_t.setText(i.get_c_num());
                    break;
                }
                check++;
            }
        }
        if (e.getSource() == getName) { //获取指定学生姓名
            int pos = Integer.parseInt(find_t.getText());
            int check = 1;
            for (Student i : Students) {
                if (check == pos) {
                    res_t.setText(i.get_name());
                    break;
                }
                check++;
            }
        }
        if (e.getSource() == getGender) { //获取指定学生性别
            int pos = Integer.parseInt(find_t.getText());
            int check = 1;
            for (Student i : Students) {
                if (check == pos) {
                    res_t.setText(i.get_gender());
                    break;
                }
                check++;
            }
        }
        if (e.getSource() == getAge) { //获取指定学生年龄
            int pos = Integer.parseInt(find_t.getText());
            int check = 1;
            for (Student i : Students) {
                if (check == pos) {
                    res_t.setText(i.get_age());
                    break;
                }
                check++;
            }
        }
        if (e.getSource() == editAge) { //修改指定学生年龄
            int pos = Integer.parseInt(find_t.getText());
            int new_age = Integer.parseInt(age.getText());
            int check = 1;
            for (Student i : Students) {
                if (check == pos) {
                    res_t.setText(i.edit_age(new_age));
                    break;
                }
                check++;
            }
        }
        if (e.getSource() == getAll) { //获取指定学生全部数据
            int pos = Integer.parseInt(find_t.getText());
            int check = 1;
            for (Student i : Students) {
                if (check == pos) {
                    res_t.setText(i.toString());
                    break;
                }
                check++;
            }
        }
    }
}