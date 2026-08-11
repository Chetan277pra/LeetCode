-- Write your PostgreSQL query statement below
SELECT  A.query_name as query_name,
(
    SELECT ROUND(AVG(rating::numeric / position), 2)
    FROM Queries 
    WHERE query_name = A.query_name
) AS quality,
(
    SELECT ROUND(100.0 * SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*) , 2)
    from Queries WHERE query_name = A.query_name 
) AS poor_query_percentage

FROM Queries as A
GROUP BY A.query_name 
