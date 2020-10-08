import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class PrimeList {
    public static void main(String[] args){
        new PrimeForm(); //创建图形界面
    }
}

class PrimeForm extends Frame implements ActionListener{
    TextField min, max, res; //创建输入框
    Button show, exit; //创建按钮
    Label l_min, l_max, l_res; //创建标签

    PrimeForm(){
        super("输出区间所有质数");
        /*初始化标签*/
        l_min = new Label("下限：");
        l_max = new Label("上限：");
        l_res = new Label("结果：");
        /*初始化文本框*/
        min = new TextField(4);
        max = new TextField(4);
        res = new TextField(15);
        /*初始化按钮*/
        show  = new Button("输出");
        exit = new Button("退出");
        setLayout(new FlowLayout());
        /*添加布局*/
        add(l_min);
        add(min);
        add(l_max);
        add(max);
        add(l_res);
        add(res);
        add(show);
        add(exit);
        /*添加事件监听*/
        show.addActionListener(this);
        exit.addActionListener(this);
        setSize(300, 200);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == show){ //监听show按钮
            ArrayList out = new ArrayList();
            int m = Integer.parseInt(min.getText());
            int n = Integer.parseInt(max.getText());
            if(m <= 0 || n <= 0){ //判断输入合法性
                res.setText("输入不合法");
                return;
            }
            for(int i = m ; i < n ; i++){ //遍历上下限
                if(isPrime(i)){ //判断
                    out.add(i + ""); //加入Arraylist
                }
            }
            String str = String.join(",", out); //转换成String并分隔
            res.setText(str); //输出
        }
        else { //监听exit按钮
            dispose();
            System.exit(0);
        }
    }

    public boolean isPrime(int n){ //质数判断
        if(n < 2){
            return false;
        }
        if(n == 2 || n == 3){
            return true;
        }else{
            int a = (int)Math.sqrt(n);
            for(int i = 2; i <= a ; i++){
                if(n % i == 0){
                    return false;
                }
            }
            return true;
        }
    }
}
