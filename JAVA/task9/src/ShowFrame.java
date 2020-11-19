import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class ShowFrame extends JFrame implements ActionListener {
    String dir = "Students.txt";
    File fl = new File(dir);
    int n;

    JButton read, write, delete;
    JLabel label;
    JTable table;
    DefaultTableModel update_table;
    JScrollPane scrollPane;

    WriteFrame wf = new WriteFrame();
    String[] colNames;
    String[][] data;

    ShowFrame() {
        n = getline(fl);
        this.setLayout(new GridLayout(3, 1, 3, 3));

        colNames = new String[] { "学号", "姓名", "性别", "班级", "语文", "数学", "英语", "体育" };
        data = new String[n][8];
        getdata(fl, data);

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
            wf.createFrame();
        }
        if (e.getSource() == delete) {
            if (fl.exists()) {
                fl.delete();
                readFile();
                label.setText("删除成功");
            }
        }
    }

    int getline(File fl) {
        if (fl.exists()) {
            try {
                FileReader fileReader = new FileReader(fl);
                LineNumberReader lineNumberReader = new LineNumberReader(fileReader);
                lineNumberReader.skip(Long.MAX_VALUE);
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

    void getdata(File fl, String[][] data) {
        if (fl.exists()) {
            try {
                FileReader fr = new FileReader(fl);
                BufferedReader br = new BufferedReader(fr);
                String str;
                for (int i = 0; i < n; i++) {
                    if ((str = br.readLine()) != null) {
                        String[] temp = str.split(",");
                        for (int j = 0; j < 8; j++) {
                            data[i][j] = temp[j];
                        }
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
        n = getline(fl);
        data = new String[n][8];
        getdata(fl, data);
        update_table.setDataVector(data, colNames);
        scrollPane.validate();
        if (n == 0) {
            label.setText("未读取到文件信息");
        } else {
            label.setText("读取完毕");
        }
    }
}
