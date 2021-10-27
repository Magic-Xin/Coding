package shumei.client;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import shumei.domain.Book;
import shumei.domain.Student;
import shumei.service.StudentService;

public class Main {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("iocbean.xml");
        StudentService studentService = (StudentService) applicationContext.getBean("studentService");
        Student student = new Student();
        student.setJszh("010");
        student.setXm("test");
//        studentService.saveStudent(student);
        student.setZym("数媒");
//        studentService.updateStudent(student);
        studentService.deleteStudent(student);

        Book book = new Book();
        book.setSm("计算机网络");
        studentService.queryStudent(book);
    }
}
