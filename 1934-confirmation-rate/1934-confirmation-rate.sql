# Write your MySQL query statement below

select 
    x.user_id ,
    round(avg(if(y.action = 'confirmed', 1, 0)), 2) as confirmation_rate 
from Signups as x
left join Confirmations as y
on x.user_id = y.user_id 
group by x.user_id