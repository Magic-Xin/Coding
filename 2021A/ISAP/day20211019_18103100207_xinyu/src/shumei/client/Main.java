package shumei.client;

import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.datasource.DriverManagerDataSource;

public class Main {
    public static void main(String[] args) {
        DriverManagerDataSource driverManagerDataSource = new DriverManagerDataSource();
        driverManagerDataSource.setDriverClassName("com.mysql.jdbc.Driver");
        driverManagerDataSource.setUrl("jdbc:mysql://localhost:3306/xsbook");
        driverManagerDataSource.setUsername("root");
        driverManagerDataSource.setPassword("");
        JdbcTemplate jdbcTemplate = new JdbcTemplate();
//        jdbcTemplate.setDataSource("insert student ("1", "1", "1");");
    }
}
