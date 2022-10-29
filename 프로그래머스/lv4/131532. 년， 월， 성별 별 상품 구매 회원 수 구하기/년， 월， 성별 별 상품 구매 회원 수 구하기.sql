-- 코드를 입력하세요
SELECT # *
       YEAR(ONL.SALES_DATE) AS YEAR
     , MONTH(ONL.SALES_DATE) AS MONTH
     , INF.GENDER
     , COUNT(DISTINCT INF.USER_ID) AS USERS
  FROM USER_INFO INF
  JOIN ONLINE_SALE ONL ON INF.USER_ID = ONL.USER_ID
 WHERE 1 = 1
   AND INF.GENDER IS NOT NULL
 GROUP BY YEAR(ONL.SALES_DATE), MONTH(ONL.SALES_DATE) , INF.GENDER
 ORDER BY YEAR(ONL.SALES_DATE), MONTH(ONL.SALES_DATE) , INF.GENDER