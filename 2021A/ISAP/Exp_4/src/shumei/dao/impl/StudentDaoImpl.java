package shumei.dao.impl;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;
import shumei.dao.StudentDao;
import shumei.domain.Book;
import shumei.domain.Student;

import java.io.InputStream;
import java.util.List;

@Repository(value = "studentDao")
public class StudentDaoImpl implements StudentDao {
    @Autowired
    private JdbcTemplate jdbcTemplate;

    @Override
    public Student findStudentByJszh() {
        try {
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            Student student = sqlSession.selectOne("Student.findStudentByJszh");
            sqlSession.close();
            return student;
        } catch (Exception e) {
            System.out.println(e);
        }
        return null;
    }

    @Override
    public Student findStudentByParam(String jszh) {
        try{
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            Student student = sqlSession.selectOne("Student.findStudentByParam", jszh);
            sqlSession.close();
            return student;
        } catch (Exception e) {
            System.out.println(e);
        }
        return null;
    }

    @Override
    public void saveStudent(Student student) {
        jdbcTemplate.update("insert into student(jszh, xm) values (?, ?)", student.getJszh(), student.getXm());
    }

    @Override
    public void updateStudent(Student student) {
        jdbcTemplate.update("update student set zym=? where jszh=?", student.getZym(), student.getJszh());
    }

    @Override
    public void queryStudent(Book book) {
        List<Student> students = jdbcTemplate.query("select jszh,xm,zym from student where jszh in (select jyls.jszh from jyls,book where jyls.isbn=book.isbn and book.sm=?);", new Object[] {book.getSm()}, new BeanPropertyRowMapper<Student>(Student.class));
        for (Student student:students) {
            System.out.println(student.getJszh() + ", " + student.getXm() + ", " + student.getZym());
        }
    }

    @Override
    public void deleteStudent(Student student) {
        jdbcTemplate.update("delete from student where jszh=?", student.getJszh());
    }
}
