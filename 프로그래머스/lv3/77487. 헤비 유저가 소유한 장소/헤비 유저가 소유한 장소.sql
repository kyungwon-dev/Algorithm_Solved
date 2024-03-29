-- 코드를 입력하세요
SELECT ID, NAME, HOST_ID
  FROM PLACES
     , (SELECT HOST_ID AS HV_ID
          FROM PLACES
         GROUP BY HOST_ID
        HAVING COUNT(HOST_ID) >= 2
        ) HEAVY
 WHERE 1 = 1
   AND HEAVY.HV_ID = PLACES.HOST_ID
 ORDER BY ID
   