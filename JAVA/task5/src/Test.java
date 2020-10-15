public class Test {
    public static void main(String[] args){
        Student stu1 = new Student("张三", 'f', 20, "10016", "数媒19-1", "信息学院", "在读");
        Teacher tea1 = new Teacher("李四", 'm', 37, 5000, "在职");
        Manager man1 = new Manager("王五", 'm', 48, 8000, 1000, "休假");
        System.out.println(stu1.getInfo());
        System.out.println(tea1.getInfo());
        System.out.println(man1.getInfo());
        System.out.println(stu1.changeSpeciality("土木工程学院", "土木19-3"));
        System.out.println(stu1.getInfo());
        System.out.println(man1.changeSalary(8000,2000));
        System.out.println(man1.getInfo());
        System.out.println(tea1.changeStatus("离职"));
        System.out.println(tea1.getInfo());
        /*多态*/
        Person stu2 = new Student("赵六", 'f', 24, "10088", "数媒19-2", "信息学院", "休学");
        System.out.println(stu2.changeStatus("毕业"));
        System.out.println(stu2.getInfo());
        stu2 = new Teacher("小胡", 'f', 44, 7000, "在职");
        System.out.println(stu2.getInfo());
    }
}
