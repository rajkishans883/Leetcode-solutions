
with dummy_table as (
    select e.*,
    Lead(num,1) over (order by id) as prev_one,
    Lead(num,2) over (order by id ) as prev_two
     from Logs as e
)
select distinct d.num as ConsecutiveNums from dummy_table d
where d.num=d.prev_one and d.num=d.prev_two;