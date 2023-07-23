-- 코드를 입력하세요
SELECT '/home/grep/src/' || B.BOARD_ID || '/' || B.FILE_ID || B.FILE_NAME || B.FILE_EXT AS FILE_PATH
  FROM USED_GOODS_FILE B
     , (
         SELECT BOARD_ID
         FROM(
         SELECT A.BOARD_ID, MAX(VIEWS)
           FROM USED_GOODS_BOARD A
          GROUP BY A.BOARD_ID
         ORDER BY MAX(VIEWS) desc
        ) A
        WHERE ROWNUM = 1
         ) A
 WHERE 1 = 1
   AND B.BOARD_ID = A.BOARD_ID
ORDER BY B.FILE_ID DESC