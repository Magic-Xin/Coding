package shumei.factory;

import shumei.service.StudentService;
import shumei.service.impl.StudentServiceImpl;

public class StaticFactory {
    public static StudentService getStudentService() {
        return new StudentServiceImpl();
    }
}
