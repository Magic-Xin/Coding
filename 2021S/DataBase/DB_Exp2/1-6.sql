use DBExperiment
select Sname, Cno, Grade
from Student, Score
where (Student.Sno = Score.Sno) and Score.Grade in
(
	select MAX(Grade)
	from Score
	where Sno = Score.Sno
	group by Sno
)