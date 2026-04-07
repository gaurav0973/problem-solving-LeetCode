# Write your MySQL query statement below

select 
    x.customer_id as customer_id,
    count(x.customer_id) as count_no_trans 
from Visits as x
left join Transactions as y
on x.visit_id = y.visit_id
where y.transaction_id is null
group by x.customer_id