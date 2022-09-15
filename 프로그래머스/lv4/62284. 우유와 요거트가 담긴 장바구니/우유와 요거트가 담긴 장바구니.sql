-- 코드를 입력하세요
select c.cart_id
  from (
      select distinct cart_id
      from CART_PRODUCTS
      where NAME = "Yogurt"
      union all
      select distinct cart_id
      from CART_PRODUCTS
      where NAME = "Milk"
  ) c
group by c.cart_id
having count(c.cart_id) >= 2
order by c.cart_id