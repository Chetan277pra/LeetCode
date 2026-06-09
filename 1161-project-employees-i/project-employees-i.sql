# Write your MySQL query statement below

SELECT A.project_id , ROUND(AVG(A.experience_years), 2) AS average_years
FROM (  
    SELECT P.project_id  , E.experience_years 
    FROM Project P
    JOIN Employee E ON P.employee_id = E.employee_id 
) AS A
GROUP BY A.project_id 