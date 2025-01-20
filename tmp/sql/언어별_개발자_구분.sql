with cte as (
    select ID, EMAIL, group_concat(NAME,'|', CATEGORY separator '|') as SKILL from DEVELOPERS
    inner join SKILLCODES
        on SKILL_CODE & CODE
    group by ID, EMAIL
)
select *
from (
    select 
        case when (SKILL like '%Front End%' and SKILL like '%Python%')
             then 'A'
             when (SKILL like '%C#%')
             then 'B'
             when (SKILL like '%Front End%')
             then 'C'
        end as GRADE
        , ID
        , EMAIL
    from cte
) as subquery
where GRADE is not NULL
order by GRADE, ID 
