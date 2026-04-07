# Write your MySQL query statement below

SELECT currDay.id
FROM Weather AS currDay
JOIN Weather AS prevDay
  ON DATEDIFF(currDay.recordDate, prevDay.recordDate) = 1
WHERE currDay.temperature > prevDay.temperature;
