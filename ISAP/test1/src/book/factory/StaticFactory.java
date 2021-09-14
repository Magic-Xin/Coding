package book.factory;

import book.service.BookService;
import book.service.impl.BookServiceImpl;

public class StaticFactory {
    public static BookService getBookService() {
        return new BookServiceImpl();
    }
}
