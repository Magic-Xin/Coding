use DBExperiment
select Score.Sno, Course.Cname, Grade
from Course,Score
where (Score.Cno='002' or Score.Cno='003') and (Course.Cno = Score.Cno)