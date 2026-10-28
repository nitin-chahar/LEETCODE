# Write your MySQL query statement below

-- SELECT 
--     d.name AS Department, 
--     e.name AS Employee, 
--     e.salary AS Salary
-- FROM 
--     Employee e 
-- JOIN 
--     Department d ON e.departmentId = d.id
-- WHERE
--     (e.departmentId, e.salary) IN (
--         SELECT departmentId, max(salary) 
--         FROM Employee 
--         GROUP BY departmentId
--     );


# Using Window Function

WITH rankedSalaries AS (
    SELECT 
        d.name AS Department, 
        e.name AS Employee, 
        e.salary AS Salary,
        RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS rnk
    FROM 
        Employee e 
    JOIN 
        Department d ON e.departmentId = d.id
)
SELECT 
    Department, Employee, Salary
FROM
    rankedSalaries
WHERE 
    rnk = 1;
