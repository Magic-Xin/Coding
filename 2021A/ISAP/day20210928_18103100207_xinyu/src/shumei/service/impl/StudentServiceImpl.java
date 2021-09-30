package shumei.service.impl;

import shumei.service.StudentService;

public class StudentServiceImpl implements StudentService {

    private String jszh;  //借书证号
    private String xm;  //姓名
    private String zym;  //专业名

    public StudentServiceImpl(String jszh, String xm, String zym) {
        this.jszh = jszh;
        this.xm = xm;
        this.zym = zym;
    }

    @Override
    public void saveStudent() {
        System.out.println("保存学生信息: 借书证号: " + jszh + ", 姓名: " + xm + ", 专业名: " + zym);
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
