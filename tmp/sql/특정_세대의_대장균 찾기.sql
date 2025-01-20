
with recursive cte(ID,PARENT_ID,n) as (
    -- 기준
    select ID,PARENT_ID,1 as n
    from ECOLI_DATA
    where PARENT_ID is null
    
    union all
    -- 조건   
    select r.ID,r.PARENT_ID, cte.n +1 as n
    from ECOLI_DATA r
    inner join cte
        on r.PARENT_ID = cte.ID
)
select ID
from cte
where n = 3