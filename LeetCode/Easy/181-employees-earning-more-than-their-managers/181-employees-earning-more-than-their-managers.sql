# Write your MySQL query statement below
select em.name as Employee
  from (select id
             , name
             , salary
             , managerId
          from Employee
         where 1 = 1
           and managerId is not Null) em
  left join Employee emp on em.managerId = emp.id
  where em.salary > emp.salary