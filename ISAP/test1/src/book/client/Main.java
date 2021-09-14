package book.client;

import book.service.BookService;
import book.service.impl.BookServiceImpl;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Main {
    public static void main(String[] args) {
        // 反射类实现 saveBook
        try {
            BookService service = (BookService) Class.forName("book.service.impl.BookServiceImpl").getDeclaredConstructor().newInstance();
            service.saveBook();
        } catch (Exception e) {
            System.out.println(e);
        }
        // 无参构造实现 updateBook
        ApplicationContext applicationContext0 = new ClassPathXmlApplicationContext("bean.xml");
        BookService service0 = (BookService) applicationContext0.getBean("bookService");
        // 静态工厂实现 queryBook
        ApplicationContext applicationContext1 = new ClassPathXmlApplicationContext("bean.xml");
        BookService service1 = (BookService) applicationContext1.getBean("staticFactory");
        service1.queryBook();
        // 实例工厂实现 deleteBook
        ApplicationContext applicationContext2 = new ClassPathXmlApplicationContext("bean.xml");
        BookService service2 = (BookService) applicationContext2.getBean("instanceFactory");
        service2.deleteBook();
    }
}
