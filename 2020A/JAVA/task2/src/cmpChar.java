import java.util.*;

public class cmpChar {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); //新建Scanner类，缓存输入
        char a = Character.MAX_VALUE; //初始化最小值
        while(scan.hasNext()){ //循环读取输入
            String s = scan.next(); //输入暂存在String
            char c = s.charAt(0); //类型转换，避免出错
            if(c == '#'){
                break; //输入为'#'时结束
            }
            if(c < a){ //比较最小值
                a = c;
            }
        }
        System.out.println("MIN: " + a); //输出最小值
    }
}
