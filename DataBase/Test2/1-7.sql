use DBExperiment
select Tname
from Teacher, Course
where Teacher.Cno = Course.Cno and Course.Cname = '数据结构'