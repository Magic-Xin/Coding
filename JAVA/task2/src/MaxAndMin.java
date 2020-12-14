import java.io.*;

public class MaxAndMin {
    public static void main(String[] args) throws IOException {
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE ; //新建最大值和最小值；
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //新建BufferedReader，缓存输入
        for(int i = 0 ; i < 10 ; i++){ //使用循环比对最大值和最小值
            String s= br.readLine();
            int input = Integer.parseInt(s);
            if(input > max){ //比较最大值
                max = input;
            }
            if(input < min){ //比较最小值
                min = input;
            }
        }
        System.out.println("Max: " + max); //输出最大值
        System.out.println("Min: " + min); //输出最小值
    }
}
