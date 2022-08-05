# Write your MySQL query statement below
SELECT name
     , population
     , area
  from World
 where area >= 3000000
 union
 SELECT name
     , population
     , area
  from World
 where population >= 25000000