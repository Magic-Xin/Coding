abstract class Person {
    protected String name;
    protected char sex;
    protected int age;

    abstract String getInfo(); //抽象输出函数
    abstract String changeStatus(String new_st); //抽象修改状态函数

    final String getName(){
        return name;
    }
}