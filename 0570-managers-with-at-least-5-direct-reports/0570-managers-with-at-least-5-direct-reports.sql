# Write your MySQL query statement below

select x.name
from Employee as x
left join Employee as y
    on x.id = y.managerId
group by x.id
having count(y.managerId) >= 5;