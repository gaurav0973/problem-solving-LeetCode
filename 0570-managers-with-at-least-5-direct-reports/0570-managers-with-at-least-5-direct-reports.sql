# Write your MySQL query statement below
 
select  x.name
from Employee as x
join Employee  as y
    on x.id = y.managerId
group by x.id, x.name
having count(y.id) >= 5