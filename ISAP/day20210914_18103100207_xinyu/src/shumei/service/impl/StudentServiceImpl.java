package shumei.service.impl;

import shumei.service.StudentService;

public class StudentServiceImpl implements StudentService {

    // 无参构造函数
    public StudentServiceImpl() {
        System.out.println("我是构造函数");
    }

    @Override
    public void saveStudent() {
        System.out.println("保存学生信息");
    }

    @Override
    public void updateStudent() {
        System.out.println("更新学生信息");
    }
}
