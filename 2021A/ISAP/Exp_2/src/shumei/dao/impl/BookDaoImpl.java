package shumei.dao.impl;
/*
 * @author Andy Xin
 * @date 2021-10-19 18:41
 */

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Repository;
import shumei.dao.BookDao;

@Repository
public class BookDaoImpl implements BookDao {
    @Value("张三")
    private String name;
    @Value("ncut202110001")
    private String num;
    @Value("数字媒体技术专业")
    private String zym;

    @Override
    public void saveBook() {
        System.out.println("执行数据库操作，保存图书信息");
        System.out.println(name + ", " + num + ", " + zym);
    }

    @Override
    public void updateBook() {
        System.out.println("执行数据库操作，更新图书信息");
    }

    @Override
    public void queryBook() {
        System.out.println("执行数据库操作，查询图书信息");
    }

    @Override
    public void deleteBook() {
        System.out.println("执行数据库操作，删除图书信息");
    }
}
