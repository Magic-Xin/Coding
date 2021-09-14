package book.service.impl;

import book.service.BookService;

public class BookServiceImpl implements BookService {

    public BookServiceImpl() {
        updateBook();
    }

    @Override
    public void saveBook() {
        System.out.println("保存图书信息");
    }

    @Override
    public void updateBook() {
        System.out.println("更新图书信息");
    }

    @Override
    public void queryBook() {
        System.out.println("查询图书信息");
    }

    @Override
    public void deleteBook() {
        System.out.println("删除图书信息");
    }
}
