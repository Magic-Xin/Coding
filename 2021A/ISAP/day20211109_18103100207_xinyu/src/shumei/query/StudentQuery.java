/*
 * @author Andy Xin
 * @date 2021-11-09 18:35
 */

package shumei.query;

import shumei.domain.Student;

public class StudentQuery {
    private Student student;
    private String bookName;

    public Student getStudent() {
        return student;
    }

    public void setStudent(Student student) {
        this.student = student;
    }

    public String getBookName() {
        return bookName;
    }

    public void setBookName(String bookName) {
        this.bookName = bookName;
    }


}