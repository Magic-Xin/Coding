package shumei.client;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import shumei.dao.BookDao;
import shumei.dao.StudentDao;
import shumei.domain.Book;
import shumei.domain.Student;
import shumei.query.StudentQuery;

import java.io.InputStream;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Book book = new Book();
        book.setIsbn("1");
        book.setSm("test");
        book.setZz("xin");
        book.setCbs("ncut");

        Student student = new Student();
        student.setXm("小");
        StudentQuery studentQuery = new StudentQuery();
        studentQuery.setStudent(student);
        studentQuery.setBookName("计算机网络");

        try {
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();

            BookDao bookDao = sqlSession.getMapper(BookDao.class);
            book = bookDao.findBookBySm("Web程序设计");
            System.out.println(book.getSm());
            bookDao.addBook(book);
            book.setSm("010");
            bookDao.updateBook(book);
            bookDao.deleteBook("1");

            StudentDao studentDao = sqlSession.getMapper(StudentDao.class);
            List<Student> students = studentDao.findStudentByQuery(studentQuery);
            for (Student s : students) {
                System.out.println(s.getXm());
            }

            List<Book> books = bookDao.findBookByStudenNameLike(studentQuery);
            for (Book b : books) {
                System.out.println(b.getSm());
            }

            sqlSession.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
