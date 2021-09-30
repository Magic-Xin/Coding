import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MTFrame extends JFrame implements ActionListener {
    static public boolean isRun = false;
    Object obj;

    JPanel mtFrame = new JPanel(new GridLayout(3, 1, 3, 3));
    JPanel Buttons = new JPanel(new GridLayout(1, 2, 3, 3));
    static JLabel time, words;
    JButton start, end;

    MTFrame(Object obj) {
        this.obj = obj;
        this.setLayout(new BorderLayout());

        time = new JLabel("");
        words = new JLabel("");
        mtFrame.add(time, BorderLayout.CENTER);
        mtFrame.add(words, BorderLayout.CENTER);

        start = new JButton("开始");
        start.addActionListener(this);
        end = new JButton("结束");
        end.addActionListener(this);
        Buttons.add(start);
        Buttons.add(end);

        mtFrame.add(Buttons);

        this.add(mtFrame, BorderLayout.CENTER);

        setVisible(true);
        setSize(300, 150);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == start) {
            isRun = true;
            synchronized (obj) {
                obj.notify();
            }
        }
        if (e.getSource() == end) {
            isRun = false;
        }
    }
}