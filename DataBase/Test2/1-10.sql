use DBExperiment
go
create view Student_CS
as
select *
from Student
where Sdept = 'CS'