# Write your MySQL query statement below
with dummy_table as (
select e.*,
    LAG(recorddate)over(order by recorddate) as prev_date,
    LAG(temperature) over(order by recorddate )as prev_temp
from weather e

)
select p.id from dummy_table p
where p.temperature>p.prev_temp
and p.recorddate= prev_date + interval 1 day;
;