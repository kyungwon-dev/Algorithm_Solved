-- 코드를 입력하세요
SELECT B.HISTORY_ID
     , A.DAILY_FEE * (TO_DATE(END_DATE) - TO_DATE(START_DATE) + 1)
       * (CASE WHEN TO_DATE(END_DATE) - TO_DATE(START_DATE) + 1 < 7
               THEN 1
               WHEN TO_DATE(END_DATE) - TO_DATE(START_DATE) + 1 < 30
               THEN (100 - (SELECT C.DISCOUNT_RATE 
                              FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN C
                             WHERE C.CAR_TYPE = '트럭'
                               AND DURATION_TYPE = '7일 이상')) / 100
               WHEN TO_DATE(END_DATE) - TO_DATE(START_DATE) + 1 < 90
               THEN (100 - (SELECT C.DISCOUNT_RATE 
                              FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN C
                             WHERE C.CAR_TYPE = '트럭'
                               AND DURATION_TYPE = '30일 이상')) / 100
               ELSE (100 - (SELECT C.DISCOUNT_RATE 
                              FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN C
                             WHERE C.CAR_TYPE = '트럭'
                               AND DURATION_TYPE = '90일 이상')) / 100
            END
         ) AS FEE
  FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY B 
     , CAR_RENTAL_COMPANY_CAR A
 WHERE 1 = 1
  AND A.CAR_ID = B.CAR_ID
  AND A.CAR_TYPE = '트럭'
ORDER BY FEE DESC, B.HISTORY_ID DESC
   