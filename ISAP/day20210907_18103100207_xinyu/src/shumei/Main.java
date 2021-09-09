package shumei;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import shumei.service.StudentService;

public class Main {

    public static void main(String[] args) {
//        StudentService service = new StudentServiceImpl();
//        service.saveStudent();
//        try {
//            StudentService service = (StudentService) Class.forName("shumei.service.impl.StudentServiceImpl").getDeclaredConstructor().newInstance();
//            service.saveStudent();
//        } catch (Exception e) {
//            System.out.println(e);
//        }
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("bean.xml");
        StudentService service = (StudentService) applicationContext.getBean("studentService");
        service.saveStudent();
    }
}
