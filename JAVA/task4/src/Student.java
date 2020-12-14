public class Student {
    /*定义各项数据类型*/
    private String s_num;
    private String c_num;
    private String name;
    private String gender;
    private int age;

    public String get_s_num() { //获取学号
        if (s_num == null) {
            return "ERROR";
        }
        String A = new String("学号：" + s_num);
        return A;
    }

    public String get_c_num() { //获取班号
        if (c_num == null) {
            return "ERROR";
        }
        String A = new String("班号：" + c_num);
        return A;
    }

    public String get_name() { //获取姓名
        if (name == null) {
            return "ERROR";
        }
        String A = new String("姓名：" + name);
        return A;
    }

    public String get_gender() { //获取性别
        if (gender == null) {
            return "ERROR";
        }
        String A = new String("性别：" + gender);
        return A;
    }

    public String get_age() { //获取年龄
        if (age == 0) {
            return "ERROR";
        }
        String A = new String("年龄：" + age);
        return A;
    }

    public String edit_age(int age) { //修改年龄
        this.age = age;
        String A = new String("修改成功");
        return A;
    }

    public String toString() { //获取全部
        return "学号：" + s_num + "，" + "班号：" + c_num + "，" + "姓名：" + name + "，" + "性别：" + gender + "，" + "年龄：" + age;
    }

    Student(String s, String c, String n, String g, int a) { //构造函数，初始化
        s_num = s;
        c_num = c;
        name = n;
        gender = g;
        age = a;
    }
}