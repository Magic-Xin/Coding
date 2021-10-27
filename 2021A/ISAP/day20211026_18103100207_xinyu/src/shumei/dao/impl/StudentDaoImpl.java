package shumei.dao.impl;

import org.springframework.jdbc.core.JdbcTemplate;
import shumei.dao.StudentDao;
import shumei.domain.Student;

public class StudentDaoImpl implements StudentDao {
    private JdbcTemplate jdbcTemplate;

    public void setJdbcTemplate(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    @Override
    public void saveStudent(Student student) {
        jdbcTemplate.update("insert into student(jszh, xm) values (?, ?)", student.getJszh(), student.getXm());
        System.out.println("保存学生信息成功Dao！");
    }
}
