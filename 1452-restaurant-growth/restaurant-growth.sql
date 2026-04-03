WITH daily AS(
    SELECT visited_on , SUM(amount) as amount
    FROM Customer
    GROUP BY visited_on
)

SELECT visited_on , 
SUM(amount) OVER (
    ORDER BY visited_on
    ROWS BETWEEN 6 PRECEDING  AND CURRENT ROW
    ) AS amount,
    ROUND(
        SUM(amount) OVER (
        ORDER BY visited_on
        ROWS BETWEEN 6 PRECEDING  AND CURRENT ROW
        ) / 7.0 , 2
    ) AS average_amount
    FROM daily
    OFFSET 6