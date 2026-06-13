# Write your MySQL query statement below
with dummy as 
(select user_id,count(follower_id) follow_count from followers
group by user_id
)
select distinct followers.user_id as user_id,dummy.follow_count as followers_count 
from followers join dummy 
on dummy.user_id=followers.user_id order by followers.user_id asc;
