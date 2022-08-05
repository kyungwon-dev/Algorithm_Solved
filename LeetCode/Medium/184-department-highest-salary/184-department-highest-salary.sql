# Write your MySQL query statement below
select (select d.name
          from Department d
         where 1 = 1
           and d.id = e.departmentId
          ) as Department
     , e.name as Employee
     , max_s as Salary
  from (
      select departmentId, max(salary) as max_s
        from employee
        group by departmentId
  ) max_salary
  , Employee e
  where e.departmentId = max_salary.departmentId
    and e.salary = max_salary.max_s