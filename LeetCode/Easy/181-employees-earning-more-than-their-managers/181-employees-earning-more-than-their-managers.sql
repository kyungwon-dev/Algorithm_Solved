# Write your MySQL query statement below
# select em.name as Employee
#   from (select id
#              , name
#              , salary
#              , managerId
#           from Employee
#          where 1 = 1
#            and managerId is not Null) em
#   left join Employee emp on em.managerId = emp.id
#   where em.salary > emp.salary
  
  select empee.Name as Employee
   from Employee empee inner join Employee emper on empee.ManagerId=emper.Id
  where empee.Salary>emper.Salary

