package shumei.service.impl;

import shumei.service.StudentService;

import java.text.SimpleDateFormat;
import java.util.Date;

public class StudentServiceImpl2 implements StudentService {

    private String jszh;  //借书证号
    private String xm;  //姓名
    private String zym;  //专业名
    private Date date;

    public void setJszh(String jszh) {
        this.jszh = jszh;
    }

    public void setXm(String xm) {
        this.xm = xm;
    }

    public void setZym(String zym) {
        this.zym = zym;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    @Override
    public void saveStudent() {
        System.out.println("保存学生信息: 借书证号: " + jszh + ", 姓名: " + xm + ", 专业名: " + zym +
                "，日期: " + new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(date));
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
