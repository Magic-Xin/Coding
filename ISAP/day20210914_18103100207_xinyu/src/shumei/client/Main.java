package shumei.client;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import shumei.service.StudentService;

public class Main {

    public static void main(String[] args) {
        // 无参构造函数调用
//        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("bean.xml");
//        StudentService service = (StudentService) applicationContext.getBean("studentService");
//        service.saveStudent();
        // 静态类工厂调用
//        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("bean.xml");
//        StudentService service = (StudentService) applicationContext.getBean("staticFactory");
//        service.saveStudent();
        // 实例工厂调用
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("bean.xml");
        StudentService service = (StudentService) applicationContext.getBean("instanceFactory");
        service.saveStudent();
    }
}
