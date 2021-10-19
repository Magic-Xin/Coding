package shumei.service.impl;
/*
 * @author Andy Xin
 * @date 2021-10-19 18:43
 */

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import shumei.dao.BookDao;
import shumei.dao.impl.BookDaoImpl;
import shumei.service.BookService;

@Service(value = "bookservice")
public class BookServiceImpl implements BookService {

//    private BookDao bookDao;
//    public void setBookDao(BookDao bookDao) {
//        this.bookDao = bookDao;
//    }

    @Autowired
    private BookDao bookDao;
    @Override
    public void saveBook() {
        System.out.println("保存图书信息");
        bookDao.saveBook();
    }

    @Override
    public void updateBook() {
        System.out.println("更新图书信息");
        bookDao.updateBook();
    }

    @Override
    public void queryBook() {
        System.out.println("查询图书信息");
        bookDao.queryBook();
    }

    @Override
    public void deleteBook() {
        System.out.println("删除图书信息");
        bookDao.deleteBook();
    }

}
