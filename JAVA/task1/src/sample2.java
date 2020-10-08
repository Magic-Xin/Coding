import java.awt.*; //引用java.awt包

public class sample2 {
    public static void main(String[] args){
        new Frame1(); //定义FrameInOut类
    }
}

class Frame1 extends Frame {
    Label lb1; //定义Label

    Frame1(){
        super("JAVA"); //定义Application标题
        lb1 = new Label("Hello world"); //定义Label内容
        add(lb1);
        setSize(300,200); //更改窗口大小
        setVisible(true); //显示窗框
    }
}