package shumei.service.impl;

import shumei.service.StudentService;

public class StudentServiceImpl implements StudentService {

    @Override
    public void saveStudent() {
        System.out.println("保存学生信息");
    }

    @Override
    public void updateStudent() {
        System.out.println("更新学生信息");
    }
}
