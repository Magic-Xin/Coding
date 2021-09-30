use DBExperiment
update Score
set Grade -= 2
where Score.Sno in 
(
	select Score.Sno
	from Score, Course, Student
	where (Score.Cno = Course.Cno and Course.Cname = '数据库原理') and Student.Ssex = '男'
)