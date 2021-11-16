package shumei.client;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.jupiter.api.Test;
import shumei.dao.BookDao;
import shumei.dao.StudentDao;
import shumei.domain.Book;
import shumei.domain.Student;
import shumei.query.StudentQuery;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

class ExpTest {
    Book book;
    StudentQuery studentQuery;
    BookDao bookDao;
    StudentDao studentDao;

    ExpTest() throws IOException {
        genBook();
        genStudentQuery();
        genDao();
    }

    void genBook(){
        book = new Book();
        book.setIsbn("1");
        book.setSm("test");
        book.setZz("xin");
        book.setCbs("ncut");
    }

    void genStudentQuery(){
        studentQuery = new StudentQuery();
        Student student = new Student();
        student.setXm("小");
        studentQuery.setStudent(student);
        studentQuery.setBookName("计算机网络");
    }

    void genDao() throws IOException {
        InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();

        bookDao = sqlSession.getMapper(BookDao.class);
        studentDao = sqlSession.getMapper(StudentDao.class);
    }

    void findBookByISBN(Book book) {
        Book tempBook = bookDao.findBookByISBN(book.getIsbn());
        if(tempBook != null) {
            System.out.println(tempBook.getSm());
        } else {
            System.out.println("null");
        }
    }

    @Test
    void addBook() {
        bookDao.addBook(book);
        findBookByISBN(book);
    }

    @Test
    void updateBook() {
        bookDao.addBook(book);
        book.setSm("010");
        bookDao.updateBook(book);
        findBookByISBN(book);
    }

    @Test
    void deleteBook() {
        bookDao.addBook(book);
        findBookByISBN(book);
        bookDao.deleteBook(book.getIsbn());
        findBookByISBN(book);
    }

    @Test
    void findBookByStudenNameLike() {
        List<Book> books = bookDao.findBookByStudenNameLike(studentQuery);
        for (Book b : books) {
            System.out.println(b.getSm());
        }
    }

    @Test
    void findStudentByQuery() {
        List<Student> students = studentDao.findStudentByQuery(studentQuery);
        for (Student s : students) {
            System.out.println(s.getXm());
        }
    }
}