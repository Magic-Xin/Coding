/*
 * @author Andy Xin
 * @date 2021-11-02 19:10
 */

package shumei.dao.impl;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import shumei.dao.BookDao;
import shumei.domain.Book;

import java.io.InputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class BookDaoImpl implements BookDao {

    @Override
    public Book findBookByISBN(String isbn) {
        try {
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            Book book = sqlSession.selectOne("Book.findBookByISBN", isbn);
            sqlSession.close();
            return book;
        } catch (Exception e) {
            System.out.println(e);
        }
        return null;
    }

    @Override
    public Book findBookBySm(String sm) {
        try {
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            Book book = sqlSession.selectOne("Book.findBookBySm", sm);
            sqlSession.close();
            return book;
        } catch (Exception e) {
            System.out.println(e);
        }
        return null;
    }

    @Override
    public List<Book> findBookBySmLike(String sm) {
        try {
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            sm = "%" + sm + "%";
            List<Book> book = sqlSession.selectList("Book.findBookBySmLike", sm);
            sqlSession.close();
            return book;
        } catch (Exception e) {
            System.out.println(e);
        }
        return null;
    }

    @Override
    public List<Book> findBookByStudenNameLike(String xm) {
        try {
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            xm = "%" + xm + "%";
            List<Book> book = sqlSession.selectList("Book.findBookByStudenNameLike", xm);
            sqlSession.close();
            return book;
        } catch (Exception e) {
            System.out.println(e);
        }
        return null;
    }

    @Override
    public void addBook(Book book) {
        Map<String, String> bookMap = new HashMap<String, String>();
        bookMap.put("isbn", book.getIsbn());
        bookMap.put("sm", book.getSm());
        bookMap.put("zz", book.getZz());
        bookMap.put("cbs", book.getCbs());
        try {
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            sqlSession.selectOne("Book.addBook", bookMap);
            sqlSession.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    @Override
    public void updateBook(Book book) {
        Map<String, String> bookMap = new HashMap<String, String>();
        bookMap.put("isbn", book.getIsbn());
        bookMap.put("sm", book.getSm());
        bookMap.put("zz", book.getZz());
        bookMap.put("cbs", book.getCbs());
        try {
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            sqlSession.selectOne("Book.updateBook", bookMap);
            sqlSession.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    @Override
    public void deleteBook(String isbn) {
        try {
            InputStream inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            sqlSession.selectOne("Book.deleteBook", isbn);
            sqlSession.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

}
