use DBExperiment
go
create table S1
(
	Sno varchar(50),
	Sname varchar(50),
	Sd varchar(50),
	Sa int,
)

go
insert into S1
select Sno, Sname, Sdept, Sage
from Student
where Sdept = 'CS'