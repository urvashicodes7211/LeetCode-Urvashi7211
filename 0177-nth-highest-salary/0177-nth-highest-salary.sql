CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    SELECT SALARY
        FROM (
            SELECT SALARY,
                   DENSE_RANK() OVER(ORDER BY SALARY DESC) AS RN
            FROM EMPLOYEE
        ) AS RESULT
        WHERE RN = N
        LIMIT 1
  );
END