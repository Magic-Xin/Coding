package shumei.dao.impl;

import org.springframework.stereotype.Repository;
import shumei.dao.StudentDao;

@Repository
public class StudentDaoImpl2 implements StudentDao {

    @Override
    public void saveStudent() {
        System.out.println("保存学生信息成功Dao！");
    }
}
