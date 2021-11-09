package shumei.dao;

import shumei.domain.Book;

import java.util.List;

public interface BookDao {
    Book findBookByISBN(String isbn);
    Book findBookBySm(String sm);
    List<Book> findBookBySmLike(String sm);
    List<Book> findBookByStudenNameLike(String xm);
    void addBook(Book book);
    void updateBook(Book book);
    void deleteBook(String isbn);
}
