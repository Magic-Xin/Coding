package shumei.client;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import shumei.dao.StudentDao;
import shumei.domain.Student;
import shumei.query.StudentQuery;

import java.io.InputStream;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        try {
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            StudentDao studentDao = sqlSession.getMapper(StudentDao.class);
//            Student student = studentDao.findStudentByJszh();
//            System.out.println(student.getXm());
            Student student = new Student();
            student.setXm("李");
            StudentQuery studentQuery = new StudentQuery();
            studentQuery.setStudent(student);
            studentQuery.setBookName("计算机网络");
            List<Student> students = studentDao.findStudentByQuery(studentQuery);
            for(Student s:students){
                System.out.println(s.getXm());
            }
            sqlSession.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
