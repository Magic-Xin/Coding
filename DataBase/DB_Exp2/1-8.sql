use DBExperiment
select Student.*
from Student
where Student.Sno in (
	select Score.Sno
	from Score, Teacher
	where Score.Cno = Teacher.Cno and Teacher.Tname = 'ÀîÕý¿Æ'
	group by Score.Sno
)
