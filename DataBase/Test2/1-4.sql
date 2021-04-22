use DBExperiment
select Tname
from Teacher,Score
where Teacher.Cno=Score.Cno
group by Tname
having COUNT(Score.Sno) > 3