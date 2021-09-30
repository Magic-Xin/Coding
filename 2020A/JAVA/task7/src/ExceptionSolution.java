import java.awt.*;
import java.io.*;
import java.net.*;

public class ExceptionSolution {
    public static void main(String[] args) {
        ArrayExp();
        IOExp();
        PtrExp();
        ArithExp();
        UrlExp();
        ClassExp();
        ArgExp();
        FileExp();
    }

    // 数组越界异常
    static void ArrayExp() {
        int[] array = { 1, 2, 3, 4, 5 };
        try {
            System.out.println(array[6]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("数组越界" + e);
        }
    }

    // IO异常
    static void IOExp() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = null;
        try {
            br.close();
            str = br.readLine();
        } catch (IOException e) {
            System.out.println("IO异常 " + e);
        }
    }

    // 空指针异常
    static void PtrExp() {
        String str = null;
        try {
            System.out.println(str.equals("test"));
        } catch (NullPointerException e) {
            System.out.println("空指针 " + e);
        }
    }

    // 计算异常
    static void ArithExp() {
        try {
            int temp = 100 / 0;
        } catch (ArithmeticException e) {
            System.out.println("算数异常 " + e);
        }
    }

    // URL异常
    static void UrlExp() {
        try {
            URL url = new URL("baidu.com");
        } catch (MalformedURLException e) {
            System.out.println("url异常 " + e);
        }
    }

    // 类文件异常
    static void ClassExp() {
        try {
            Class test = Class.forName("Test");
        } catch (ClassNotFoundException e) {
            System.out.println("类文件不存在 " + e);
        }
    }

    // 非法参数
    static void ArgExp() {
        File f = new File("/Users/xinyu/Desktop/Coding/JAVA/task8/src/test.txt");
        try {
            Desktop.getDesktop().open(f);
        } catch (IOException | IllegalArgumentException e) {
            System.out.println("非法参数 " + e);
        }
    }

    // 文件不存在
    static void FileExp() {
        try {
            FileWriter fw = new FileWriter("W:/test.txt");
        } catch (IOException e) {
            System.out.println("文件不存在 " + e);
        }
    }
}