# Write your MySQL query statement below

with product_group as (
    select product_id,sum(unit) as unit from orders
    where year(order_date)=2020 and month(order_date)=2 
    group by product_id
)
select p.product_name,g.unit
 from product_group g join products p on p.product_id=g.product_id
 where unit >=100;
