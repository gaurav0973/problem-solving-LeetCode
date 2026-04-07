# Write your MySQL query statement below

select y.unique_id, x.name
from Employees as x
left join EmployeeUNI as y
on x.id = y.id 
