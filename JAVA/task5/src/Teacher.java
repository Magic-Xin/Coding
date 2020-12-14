final class Teacher extends Person {
    private int sal;
    private String status;

    Teacher(String n, char x, int a, int s, String st){ //构造函数
        this.name = n;
        this.sex = x;
        this.age = a;
        this.sal = s;
        this.status = st;
    }

    String getInfo() { //重载输出信息
        return "姓名："+name+" 性别："+sex+" 年龄："+age+" 薪资："+sal+" 在职状态："+status;
    }

    final String changeSalary(int new_sal){ //修改薪资
        if(new_sal < 1000){
            new_sal = 1000;
        }
        this.sal= new_sal;
        return "修改薪资成功";
    }

    String changeStatus(String new_st){ //重载修改在职状态
        this.status = new_st;
        return "改变在职状态成功";
    }
}
