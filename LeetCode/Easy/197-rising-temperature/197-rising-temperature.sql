SELECT w2.id
  FROM Weather w1
     , Weather w2
 WHERE 1 = 1
   AND DATE_ADD(w1.recordDate, INTERVAL 1 DAY) = w2.recordDate
   AND w1.temperature < w2.temperature