package shumei.dao;

import shumei.domain.Book;
import shumei.domain.Student;

public interface StudentDao {
    void saveStudent(Student student);
    void updateStudent(Student student);
    void queryStudent(Book book);
    void deleteStudent(Student student);
}
