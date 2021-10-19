package shumei.service.impl;
/*
 * @author Andy Xin
 * @date 2021-10-12 18:33
 */

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import shumei.dao.StudentDao;
import shumei.service.StudentService;

@Service(value = "stdService")
public class StudentServiceImpl3 implements StudentService {
    @Autowired
    private StudentDao studentDao;
    @Override
    public void saveStudent() {
        System.out.println("保存学生信息成功3!");
        studentDao.saveStudent();
    }

    @Override
    public void updateStudent() {

    }

    @Override
    public void queryStudent() {

    }

    @Override
    public void deleteStudent() {

    }
}
