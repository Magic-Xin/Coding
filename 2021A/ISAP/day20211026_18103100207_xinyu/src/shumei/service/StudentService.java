package shumei.service;

import shumei.domain.Student;

public interface StudentService {
    void saveStudent(Student student);
    void updateStudent();
    void queryStudent();
    void deleteStudent();
}
