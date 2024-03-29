-- 코드를 입력하세요
SELECT INF.REST_ID
     , INF.REST_NAME
     , INF.FOOD_TYPE
     , INF.FAVORITES
     , INF.ADDRESS
     , ROUND(AVG(REV.REVIEW_SCORE),2) AS SCORE
  FROM REST_INFO INF
  INNER JOIN REST_REVIEW REV ON INF.REST_ID = REV.REST_ID
 WHERE 1 = 1
   AND INF.ADDRESS LIKE '서울%'
 GROUP BY INF.REST_ID
 ORDER BY SCORE DESC, INF.FAVORITES DESC