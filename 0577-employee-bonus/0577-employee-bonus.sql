# Write your MySQL query statement below


select 
    x.name,
    y.bonus
from Employee as x
left join Bonus as y
on x.empId = y.empId       
where y.bonus < 1000 or 
    y.bonus is null
