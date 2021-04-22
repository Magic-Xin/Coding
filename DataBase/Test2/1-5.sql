use DBExperiment
select Sname, Sdept
from Student
where Sno not in (
select Sno
from Score
group by Sno)