# Write your MySQL query statement below

with temp as(
select class,count(student) as count_students 
 from courses
group by class
)
select class from temp
where temp.count_students>=5;