import javax.swing.*;
import java.sql.*;

public class CheckDatabase {
    String url = "jdbc:mysql://";
    String username;
    String password;

    Connection connection;
    Statement statement;
    ResultSet resultSet;

    JTextArea show;
    JScrollPane scrollPane;

    CheckDatabase(String url, String usr, String passwd, JTextArea show, JScrollPane scrollPane){
        this.url += url;
        this.username = usr;
        this.password = passwd;
        this.show = show;
        this.scrollPane = scrollPane;
        clear();
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(this.url,this.username,this.password);
            statement = connection.createStatement();
            show.append("连接成功！");
            scrollPane.validate();
            CheckFrame.isRun = true;
        } catch (Exception e){
            e.printStackTrace();
            show.append("连接失败！");
            scrollPane.validate();
        }
    }

    public void disconnect(){
        clear();
        try {
            statement.close();
            connection.close();
            show.append("断开成功！");
            scrollPane.validate();
            CheckFrame.isRun = false;
        } catch (Exception e){
            e.printStackTrace();
            show.append("断开失败！");
            scrollPane.validate();
        }
    }

    public void check1(){
        String sql = "select Sno,Sname,Sage from Student";
        clear();
        try{
            resultSet = statement.executeQuery(sql);
            while(resultSet.next()){
                String no = resultSet.getString("Sno");
                String name = resultSet.getString("Sname");
                int age = resultSet.getInt("Sage");
                String res = no+" "+name+" "+age+"\n";
                showText(res);
            }
            resultSet.close();
        } catch (Exception e){
            e.printStackTrace();
            showText("操作失败！");
        }
    }

    public void check2(){
        String sql = "select Sdept,count(Sno) from Student group by Sdept order by count(Sno) desc";
        clear();
        try{
            resultSet = statement.executeQuery(sql);
            while(resultSet.next()){
                String dept = resultSet.getString("Sdept");
                int count = resultSet.getInt("count(Sno)");
                String res = dept+" "+count+"\n";
                showText(res);
            }
            resultSet.close();
        } catch (Exception e){
            e.printStackTrace();
            showText("操作失败！");
        }
    }

    public void check3(){
        String sql = "select Student.Sno,Course.Cname,Grade from Student,Score,Course where(Score.Cno='002' or Score.Cno='003') and (Course.Cno = Score.Cno) and (Student.Sno = Score.Sno)";
        clear();
        try{
            resultSet = statement.executeQuery(sql);
            while(resultSet.next()){
                String no = resultSet.getString("Sno");
                String name = resultSet.getString("Cname");
                int grade = resultSet.getInt("Grade");
                String res = no+" "+name+" "+grade+"\n";
                showText(res);
            }
            resultSet.close();
        } catch (Exception e){
            e.printStackTrace();
            showText("操作失败！");
        }
    }

    public void check4(){
        String sql = "select Tname from Teacher,Score where Teacher.Cno = Score.Cno group by Tname having COUNT(SCore.Sno)>3";
        clear();
        try{
            resultSet = statement.executeQuery(sql);
            while(resultSet.next()){
                String name = resultSet.getString("Tname");
                String res = name+"\n";
                showText(res);
            }
            resultSet.close();
        } catch (Exception e){
            e.printStackTrace();
            showText("操作失败！");
        }
    }

    public void check5(){
        String sql = "select Sname,Sdept from Student where Sno not in (select Sno from Score group by Sno)";
        clear();
        try{
            resultSet = statement.executeQuery(sql);
            while(resultSet.next()){
                String name = resultSet.getString("Sname");
                String dept = resultSet.getString("Sdept");
                String res = name+" "+dept+"\n";
                showText(res);
            }
            resultSet.close();
        } catch (Exception e){
            e.printStackTrace();
            showText("操作失败！");
        }
    }

    public void check6(){
        String sql = "select Sname,Cno,Grade from Score y,Student";
        clear();
        try{
            resultSet = statement.executeQuery(sql);
            while(resultSet.next()){
                String name = resultSet.getString("Sname");
                int no = resultSet.getInt("Cno");
                int grade = resultSet.getInt("Grade");
                String res = name+" "+no+" "+grade+"\n";
                showText(res);
            }
            resultSet.close();
        } catch (Exception e){
            e.printStackTrace();
            showText("操作失败！");
        }
    }

    public void check7(){
        String sql = "select distinct Tname from Teacher where Cno in (Select Cno from course where Teacher.Cno = Course.Cno and Course.Cname = '数据结构')";
        clear();
        try{
            resultSet = statement.executeQuery(sql);
            while(resultSet.next()){
                String name = resultSet.getString("Tname");
                String res = name+"\n";
                showText(res);
            }
            resultSet.close();
        } catch (Exception e){
            e.printStackTrace();
            showText("操作失败！");
        }
    }

    public void check8(){
        String sql = "select Student.Sno,Sname,Ssex,Sdept,Sage from Student,Teacher,Score where Teacher.Tname = '李正科' and Student.Sno = Score.Sno and Teacher.Cno = Score.Cno group by Student.Sno,Sname,Ssex,Sdept,Sage";
        clear();
        try{
            resultSet = statement.executeQuery(sql);
            while(resultSet.next()){
                String no = resultSet.getString("Sno");
                String name = resultSet.getString("Sname");
                String sex = resultSet.getString("Ssex");
                String dept = resultSet.getString("Sdept");
                int age = resultSet.getInt("Sage");
                String res = no+" "+name+" "+sex+" "+dept+" "+age+"\n";
                showText(res);
            }
            resultSet.close();
        } catch (Exception e){
            e.printStackTrace();
            showText("操作失败！");
        }
    }

    public void check9(){
        clear();
        try{
            String sql = "DROP TABLE IF EXISTS `S1`";
            statement.executeUpdate(sql);
            sql = "CREATE TABLE `S1` ( `SNO` VARCHAR(10) NOT NULL COMMENT '学号', `SNAME` VARCHAR(20) DEFAULT NULL COMMENT '姓名', `SD` VARCHAR(50) DEFAULT NULL COMMENT '系别', `SA` INT(4) UNSIGNED ZEROFILL DEFAULT NULL COMMENT '年龄', PRIMARY KEY (`SNO`)) ENGINE=INNODB DEFAULT CHARSET=utf8";
            statement.executeUpdate(sql);
            showText("建立完成！\n");
            sql = "INSERT INTO S1(SNO,SNAME,SD,SA) SELECT s.SNO,s.SNAME,s.SDEPT AS SD,s.SAGE AS SA FROM student s WHERE s.SDEPT='CS'";
            statement.executeUpdate(sql);
            showText("插入完成！\n");
            sql = "select * from S1";
            resultSet = statement.executeQuery(sql);
            while(resultSet.next()){
                String no = resultSet.getString("Sno");
                String name = resultSet.getString("Sname");
                String sd = resultSet.getString("SD");
                int sa = resultSet.getInt("SA");
                String res = no+" "+name+" "+sd+" "+sa+"\n";
                showText(res);
            }
            resultSet.close();
        } catch (Exception e){
            e.printStackTrace();
            showText("操作失败！");
        }
    }

    public void check10(){
        clear();
        try{
            String sql = "DROP VIEW IF EXISTS `V_STUDENT_CS`";
            statement.executeUpdate(sql);
            sql = "CREATE VIEW V_STUDENT_CS AS SELECT s.SNO,s.SNAME,s.SSEX,s.SDEPT,s.SAGE,c.GRADE FROM student s ,score c WHERE s.SNO = c.SNO";
            statement.executeUpdate(sql);
            showText("建立完成！\n");
            sql = "select * from V_STUDENT_CS";
            resultSet = statement.executeQuery(sql);
            while(resultSet.next()){
                String no = resultSet.getString("SNO");
                String name = resultSet.getString("SNAME");
                String sex = resultSet.getString("SSEX");
                String dept = resultSet.getString("SDEPT");
                int age = resultSet.getInt("SAGE");
                int grade = resultSet.getInt("GRADE");
                String res = no+" "+name+" "+sex+" "+dept+" "+age+" "+grade+"\n";
                showText(res);
            }
            resultSet.close();
        } catch (Exception e){
            e.printStackTrace();
            showText("操作失败！");
        }
    }

    public void check11(){
        clear();
        Runnable runnable = new ArgsFrame(this);
        Thread thread = new Thread(runnable);
        thread.run();
    }

    public void clear(){
        show.setText("");
        scrollPane.validate();
    }

    public void showText(String str){
        show.append(str);
        scrollPane.validate();
    }
}
