-- 코드를 작성해주세요
SELECT  INFO.ITEM_ID
     ,  INFO.ITEM_NAME
FROM    ITEM_INFO INFO
WHERE   INFO.ITEM_ID IN (SELECT ITEM_ID T FROM ITEM_TREE T WHERE T.PARENT_ITEM_ID IS NULL)