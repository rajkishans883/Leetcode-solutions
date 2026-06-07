CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN


  RETURN (
        select distinct salary from
       ( select *,
        dense_rank() over(order by salary desc) as rn
        from employee) as x
        where x.rn =n
  );
END