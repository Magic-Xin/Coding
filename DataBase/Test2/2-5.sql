use DBExperiment
select Course.Cno, Course.Cname, AVG(Grade) as Avrage
from Course, Score
where Course.Cno = Score.Cno
group by Course.Cno, Course.Cname
having AVG(Grade) > 60