package shumei.client;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import shumei.dao.StudentDao;
import shumei.dao.impl.StudentDaoImpl;
import shumei.service.StudentService;

public class Main {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("bean.xml");
        StudentService studentService1 = (StudentService) applicationContext.getBean("studentService");
        studentService1.saveStudent();

        StudentService studentService2 = (StudentService) applicationContext.getBean("studentService2");
        studentService2.saveStudent();

        ApplicationContext applicationContext1 = new ClassPathXmlApplicationContext("iocbean.xml");
        StudentService studentService3 = (StudentService) applicationContext1.getBean("stdService");
        studentService3.saveStudent();
        StudentDao studentDao = (StudentDao) applicationContext1.getBean("studentDaoImpl");
        studentDao.saveStudent();
    }
}
