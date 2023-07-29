SELECT EXTRACT(YEAR FROM s.sales_date) AS year,
       EXTRACT(MONTH FROM s.sales_date) AS month,
       COUNT(DISTINCT s.user_id) AS puchased_users,
       ROUND(COUNT(DISTINCT s.user_id) / (SELECT COUNT(user_id)
                                            FROM user_info
                                           WHERE EXTRACT(YEAR FROM joined) = 2021), 1)
                                              AS puchased_ratio
  FROM user_info i
 INNER JOIN online_sale s
    ON i.user_id = s.user_id
 WHERE EXTRACT(YEAR FROM i.joined) = 2021
 GROUP BY EXTRACT(YEAR FROM s.sales_date),
          EXTRACT(MONTH FROM s.sales_date)
 ORDER BY year ASC, month ASC;