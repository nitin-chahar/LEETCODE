SELECT 
    emp.name AS Employee
FROM 
    Employee AS emp
JOIN 
    Employee AS mgr 
    ON emp.managerId = mgr.id
WHERE 
    emp.salary > mgr.salary;