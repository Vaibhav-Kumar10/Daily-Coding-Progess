WITH RankedSalaries AS (
    SELECT salary, 
    DENSE_RANK() OVER (ORDER BY SALARY DESC) AS SALARY_RANK
    FROM EMPLOYEE
)
SELECT (
    SELECT DISTINCT SALARY 
    FROM RankedSalaries
    WHERE SALARY_RANK = 2
    )
 as SecondHighestSalary
;
/*
SELECT (
    SELECT DISTINCT salary 
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;
*/
/*
SELECT MAX(salary) as SecondHighestSalary
FROM Employee
WHERE salary < (
    SELECT MAX(salary) 
    FROM Employee
);
*/