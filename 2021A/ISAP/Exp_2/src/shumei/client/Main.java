package shumei.client;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import shumei.service.BookService;

public class Main {
    public static void main(String[] args) {

        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("iocbean.xml");
        BookService bookService = (BookService) applicationContext.getBean("bookservice");
        bookService.saveBook();
        bookService.updateBook();
        bookService.queryBook();
        bookService.deleteBook();

    }
}
