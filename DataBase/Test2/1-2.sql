use DBExperiment
select Sdept,COUNT(Sdept) as '������'
from Student
group by Sdept
order by '������' DESC