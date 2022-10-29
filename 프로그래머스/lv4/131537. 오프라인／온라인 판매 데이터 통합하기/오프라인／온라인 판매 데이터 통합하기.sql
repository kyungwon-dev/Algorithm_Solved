-- 코드를 입력하세요
SELECT RS.SALES_DATE
     , RS.PRODUCT_ID
     , RS.USER_ID
     , RS.SALES_AMOUNT
  FROM (
        SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d') AS SALES_DATE
             , PRODUCT_ID
             , USER_ID
             , SALES_AMOUNT
          FROM ONLINE_SALE
         WHERE 1 = 1
           AND YEAR(SALES_DATE) = 2022
           AND MONTH(SALES_DATE) = 03
         UNION ALL
         SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d') AS SALES_DATE
             , PRODUCT_ID
             , NULL AS USER_ID
             , SALES_AMOUNT
          FROM OFFLINE_SALE
         WHERE 1 = 1
           AND YEAR(SALES_DATE) = 2022
           AND MONTH(SALES_DATE) = 03
        ) RS
 WHERE 1 = 1
 ORDER BY RS.SALES_DATE ASC, RS.PRODUCT_ID ASC, RS.USER_ID ASC