final class Manager extends Person {
    private int sal;
    private int sal_plus;
    private String status;

    Manager(String n, char x, int a, int sl, int slp, String st){ //构造函数
        this.name = n;
        this.sex = x;
        this.age = a;
        this.sal = sl;
        this.sal_plus = slp;
        this.status = st;
    }

    String getInfo() { //重载输出信息
        int final_sal = this.sal+this.sal_plus;
        return "姓名："+name+" 性别："+sex+" 年龄："+age+" 总薪资："+final_sal+" 在职状态："+status;
    }

    String changeStatus(String new_st){ //重载修改在职状态
        this.status = new_st;
        return "改变在职状态成功";
    }

    final String changeSalary(int new_sal, int new_sal_plus){ //修改薪资及津贴
        if(new_sal < 1000){
            new_sal = 1000;
        }
        if(new_sal_plus < 500){
            new_sal_plus = 500;
        }
        this.sal = new_sal;
        this.sal_plus = new_sal_plus;
        return "修改薪资及津贴成功";
    }
}
