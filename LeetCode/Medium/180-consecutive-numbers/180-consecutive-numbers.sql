# Write your MySQL query statement below
select distinct m as ConsecutiveNums
  from (
        select num as m
             , lag(num,1,'N') over (order by id) as p
             , lead(num,1,'N') over (order by id) as n
         from Logs
      ) log
  where log.m = log.p
    and log.p = log.n