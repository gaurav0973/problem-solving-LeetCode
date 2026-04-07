# Write your MySQL query statement below


select x.id 
from Weather as x
left join Weather as y
on x.recordDate - Interval 1 Day = y.recordDate
where x.temperature > y.temperature;