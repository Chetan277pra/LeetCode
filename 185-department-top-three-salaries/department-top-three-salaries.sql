# Write your MySQL query statement below
SELECT Department , Employee , Salary
FROM (
SELECT B.name as Department , A.name as Employee, A.Salary as Salary,
DENSE_RANK() OVER(PARTITION BY A.departmentId ORDER BY A.Salary desc) AS DR
FROM Employee as A
JOIN Department as B  
ON A.departmentId  = B.id
) as t
 WHERE DR <= 3


