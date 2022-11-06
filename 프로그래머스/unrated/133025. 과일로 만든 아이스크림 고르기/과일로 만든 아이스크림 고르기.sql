# -- 코드를 입력하세요
SELECT HF.FLAVOR
  FROM FIRST_HALF HF
  JOIN ICECREAM_INFO INF ON INF.FLAVOR = HF.FLAVOR
 WHERE 1 = 1
   AND INF.INGREDIENT_TYPE = 'fruit_based'
   AND HF.TOTAL_ORDER >= 3000
 ORDER BY HF.TOTAL_ORDER DESC;