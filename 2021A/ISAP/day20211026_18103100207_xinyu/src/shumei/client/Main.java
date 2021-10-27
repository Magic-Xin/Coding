package shumei.client;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import shumei.domain.Student;
import shumei.service.StudentService;

import java.util.List;

public class Main {
    public static void main(String[] args) {

        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("bean.xml");
//        JdbcTemplate jdbcTemplate = (JdbcTemplate) applicationContext.getBean("jdbcTemplate");
//        jdbcTemplate.update("insert into student(jszh, xm) values ('106', 'mike')");
//        jdbcTemplate.update("update student set zym=? where jszh=?", "数字媒体技术","106");
//        jdbcTemplate.update("delete from student where jszh='106'");
//        List<Student> students = jdbcTemplate.query("select * from student", new BeanPropertyRowMapper<Student>(Student.class));
//        for (Student student:students) {
//            System.out.println(student.getXm());
//        }
        StudentService studentService = (StudentService) applicationContext.getBean("studentService");
        Student student = new Student();
        student.setJszh("106");
        student.setXm("mike");
        studentService.saveStudent(student);
    }
}
