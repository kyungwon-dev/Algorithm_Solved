-- 코드를 입력하세요
SELECT COUNT(AGE) AS USERS
  FROM USER_INFO
 WHERE 1 = 1
   AND AGE IS NOT NULL
   AND AGE BETWEEN 20 AND 29
   AND YEAR(JOINED) = 2021
  