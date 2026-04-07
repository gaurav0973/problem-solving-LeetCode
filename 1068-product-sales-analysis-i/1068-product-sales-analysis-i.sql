# Write your MySQL query statement below


select 
    y.product_name,
    x.year,
    x.price
from Sales as x
left join Product as y
on x.product_id = y.product_id 