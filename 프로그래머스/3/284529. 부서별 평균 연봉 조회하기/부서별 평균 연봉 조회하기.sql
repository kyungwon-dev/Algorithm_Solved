-- 코드를 작성해주세요
SELECT  DEP.DEPT_ID AS DEPT_ID
    ,   DEP.DEPT_NAME_EN AS DEPT_NAME_EN
    ,   ROUND(AVG(EMP.SAL),0) AS AVG_SAL
FROM    HR_DEPARTMENT DEP
   ,    HR_EMPLOYEES  EMP
WHERE   DEP.DEPT_ID = EMP.DEPT_ID
GROUP BY DEP.DEPT_ID, DEP.DEPT_NAME_EN
ORDER BY ROUND(AVG(EMP.SAL),0) DESC