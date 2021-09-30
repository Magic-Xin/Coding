final class Student extends Person {
    private String num;
    private String c_name;
    private String s_name;
    private String status;

    Student(String n, char x, int a, String m, String c, String s, String st){ //构造函数
        this.name = n;
        this.sex = x;
        this.age = a;
        this.num = m;
        this.c_name = c;
        this.s_name = s;
        this.status = st;
    }

    String getInfo(){ //重载输出
        return "姓名："+name+" 性别："+sex+" 年龄："+age+" 学号："+num+" 班级："+c_name+" 学院："+s_name+" 学籍状态："+status;
    }

    final String changeSpeciality(String new_s_name, String new_c_name){ //转专业，修改班级和学院
        this.s_name = new_s_name;
        this.c_name = new_c_name;
        return "转专业成功";
    }

    String changeStatus(String new_st){ //重载修改学籍状态
        this.status = new_st;
        return "改变学籍状态成功";
    }
}
