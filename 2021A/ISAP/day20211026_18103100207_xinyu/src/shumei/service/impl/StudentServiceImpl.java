package shumei.service.impl;
/*
 * @author Andy Xin
 * @date 2021-10-12 18:33
 */

import shumei.dao.StudentDao;
import shumei.domain.Student;
import shumei.service.StudentService;

public class StudentServiceImpl implements StudentService {
    private StudentDao studentDao;

    public void setStudentDao(StudentDao studentDao) {
        this.studentDao = studentDao;
    }

    @Override
    public void saveStudent(Student student) {
        studentDao.saveStudent(student);
        System.out.println("保存学生信息!");
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
