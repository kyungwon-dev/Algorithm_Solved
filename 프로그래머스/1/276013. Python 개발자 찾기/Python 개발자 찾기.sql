-- 코드를 작성해주세요
SELECT  A.ID, A.EMAIL, A.FIRST_NAME, A.LAST_NAME
FROM    DEVELOPER_INFOS A
WHERE   A.SKILL_1 = 'Python'
OR     A.SKILL_3 = 'Python'
OR     A.SKILL_2 = 'Python'
ORDER BY ID ASC;