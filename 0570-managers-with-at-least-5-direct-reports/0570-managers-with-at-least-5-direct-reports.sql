# Write your MySQL query statement below

SELECT x.name
FROM Employee AS x
JOIN Employee AS y
    ON x.id = y.managerId
GROUP BY x.id, x.name
HAVING COUNT(y.id) >= 5;