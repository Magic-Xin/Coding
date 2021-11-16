package shumei.dao;

import shumei.domain.Book;
import shumei.domain.Student;
import shumei.query.StudentQuery;

import java.util.List;

public interface StudentDao {
    Student findStudentByJszh();
    Student findStudentByParam(String jszh);
    void saveStudent(Student student);
    void updateStudent(Student student);
    void queryStudent(Book book);
    void deleteStudent(Student student);
    List<Student> findStudentByQuery(StudentQuery studentQuery);
}
