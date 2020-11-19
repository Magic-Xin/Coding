import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class ShowFrame extends JFrame implements ActionListener {
    String dir = "Students.txt";
    File fl = new File(dir);

    static boolean isRun = false;
    int n;

    JButton read, write, delete;
    JLabel label;
    JTable table;
    DefaultTableModel update_table;
    JScrollPane scrollPane;

    String[] colNames;
    String[][] data;

    ShowFrame() {
        n = getLine(fl);
        this.setLayout(new GridLayout(3, 1, 3, 3));

        colNames = new String[] { "学号", "姓名", "性别", "班级", "语文", "数学", "英语", "体育" };
        data = new String[n][8];
        getData(fl, data);

        update_table = new DefaultTableModel(data, colNames);
        table = new JTable(update_table);
        scrollPane = new JScrollPane(table);
        this.add(scrollPane);

        if (n == 0) {
            label = new JLabel("未读取到文件信息");
        } else {
            label = new JLabel("读取完毕");
        }
        this.add(label);

        read = new JButton("读取");
        read.addActionListener(this);
        write = new JButton("录入");
        write.addActionListener(this);
        delete = new JButton("删除");
        delete.addActionListener(this);
        JPanel Buttons = new JPanel(new FlowLayout());
        Buttons.add(read);
        Buttons.add(write);
        Buttons.add(delete);
        this.add(Buttons);

        setVisible(true);
        setSize(500, 400);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == read) {
            readFile();
        }
        if (e.getSource() == write) {
            if (isRun) {
                label.setText("窗口运行中");
            } else {
                Runnable r = new WriteFrame();
                Thread t = new Thread(r);
                t.start();
            }
        }
        if (e.getSource() == delete) {
            if (fl.exists()) {
                if (fl.delete()) {
                    readFile();
                    label.setText("删除成功");
                } else {
                    label.setText("删除失败");
                }
            }
        }
    }

    int getLine(File fl) {
        if (fl.exists()) {
            try {
                FileReader fileReader = new FileReader(fl);
                LineNumberReader lineNumberReader = new LineNumberReader(fileReader);
                int lines = lineNumberReader.getLineNumber() + 1;
                fileReader.close();
                lineNumberReader.close();
                return lines;
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return 0;
    }

    void getData(File fl, String[][] data) {
        if (fl.exists()) {
            try {
                FileReader fr = new FileReader(fl);
                BufferedReader br = new BufferedReader(fr);
                String str;
                for (int i = 0; i < n; i++) {
                    if ((str = br.readLine()) != null) {
                        String[] temp = str.split(",");
                        System.arraycopy(temp, 0, data[i], 0, 8);
                    }
                }
                br.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    void readFile() {
        fl = new File(dir);
        n = getLine(fl);
        data = new String[n][8];
        getData(fl, data);
        update_table.setDataVector(data, colNames);
        scrollPane.validate();
        if (n == 0) {
            label.setText("未读取到文件信息");
        } else {
            label.setText("读取完毕");
        }
    }
}
