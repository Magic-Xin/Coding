package shumei.factory;

import shumei.service.StudentService;
import shumei.service.impl.StudentServiceImpl;

public class InsFactory {
    public StudentService getStudentService() {
        return new StudentServiceImpl();
    }
}
