
with RECURSIVE cte(ID,PARENT_ID,n) as (
    -- 기준이 되는 쿼리 
    SELECT ID, PARENT_ID, 1 AS n
    FROM ECOLI_DATA
    WHERE PARENT_ID is null 
    union all 
    -- 여기서 부터 조건문임 
    select r.ID,
           r.PARENT_ID,
           cte.n + 1 as n 
    from ECOLI_DATA r 
    inner join cte
        on r.PARENT_ID = cte.ID
)
select count(A.n) as COUNT , A.n as GENERATION from cte as A
left outer join cte as B
    on A.ID = B.PARENT_ID
where B.PARENT_ID IS NULL 
group by A.n ; 