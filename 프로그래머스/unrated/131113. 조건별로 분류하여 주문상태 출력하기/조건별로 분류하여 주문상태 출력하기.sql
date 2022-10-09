-- 코드를 입력하세요
SELECT ORDER_ID
     , PRODUCT_ID
     , OUT_DATE
     , CASE WHEN OUT_DATE IS NULL
            THEN "출고미정"
            WHEN MONTH(OUT_DATE) < '5'
            THEN "출고완료"
            WHEN MONTH(OUT_DATE) = '5' AND DAY(OUT_DATE) <= '1'
            THEN "출고완료"
            ELSE "출고대기"
       END AS 출고여부
  FROM FOOD_ORDER
 WHERE 1 = 1
   AND IN_DATE IS NOT NULL
   