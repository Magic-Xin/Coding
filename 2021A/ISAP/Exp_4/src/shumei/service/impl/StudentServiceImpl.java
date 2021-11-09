package shumei.service.impl;
/*
 * @author Andy Xin
 * @date 2021-10-12 18:33
 */

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import shumei.dao.StudentDao;
import shumei.domain.Book;
import shumei.domain.Student;
import shumei.service.StudentService;

@Service(value = "studentService")
public class StudentServiceImpl implements StudentService {
    @Autowired
    private StudentDao studentDao;

    @Override
    public void saveStudent(Student student) {
        studentDao.saveStudent(student);
        System.out.println("保存学生信息!");
    }

    @Override
    public void updateStudent(Student student) {
        studentDao.updateStudent(student);
        System.out.println("更新学生信息!");
    }

    @Override
    public void queryStudent(Book book) {
        studentDao.queryStudent(book);
        System.out.println("查询学生信息!");
    }

    @Override
    public void deleteStudent(Student student) {
        studentDao.deleteStudent(student);
        System.out.println("删除学生信息!");
    }
}
