# Write your MySQL query statement below
select name
  from Customer
 where 1 = 1
   and coalesce(referee_id,'1') != 2