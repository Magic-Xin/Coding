package shumei.client;

import shumei.dao.BookDao;
import shumei.dao.impl.BookDaoImpl;
import shumei.domain.Book;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        BookDao bookDao = new BookDaoImpl();

        Book book = bookDao.findBookByISBN("7-111-10162-0");
        System.out.println("ISBN: " + book.getIsbn() + " sm: " + book.getSm() + " zz: " + book.getZz() + " cbs: " + book.getCbs());

        book = bookDao.findBookBySm("ASP.NET程序设计");
        System.out.println("ISBN: " + book.getIsbn() + " sm: " + book.getSm() + " zz: " + book.getZz() + " cbs: " + book.getCbs());

        List<Book> bookList = bookDao.findBookBySmLike("Web");
        for (Book books:bookList) {
            System.out.println("ISBN: " + books.getIsbn() + " sm: " + books.getSm() + " zz: " + books.getZz() + " cbs: " + books.getCbs());
        }

        book.setIsbn("7-505-37908-9");
        book.setSm("Web程序");
        book.setZz("krs");
        book.setCbs("st");
        bookDao.addBook(book);
        book.setSm("shumei");
        bookDao.updateBook(book);
        bookDao.deleteBook(book.getIsbn());

        bookList = bookDao.findBookByStudenNameLike("小");
        for (Book books:bookList) {
            System.out.println("ISBN: " + books.getIsbn() + " sm: " + books.getSm() + " zz: " + books.getZz() + " cbs: " + books.getCbs());
        }
    }
}
