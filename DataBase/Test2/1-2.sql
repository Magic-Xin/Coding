use DBExperiment
select Sdept,COUNT(Sdept) as '总人数'
from Student
group by Sdept
order by '总人数' DESC