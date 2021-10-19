package book.factory;

import book.service.BookService;
import book.service.impl.BookServiceImpl;

public class InsFactory {
    public BookService getBookService() {
        return new BookServiceImpl();
    }
}
