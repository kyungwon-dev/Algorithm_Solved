# Write your MySQL query statement below
select Customers.name as Customers
  from Customers
 where 1 = 1
   and Customers.id not in (select customerId from Orders)
