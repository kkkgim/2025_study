select distinct ID,EMAIL,FIRST_NAME,LAST_NAME
from DEVELOPERS a, SKILLCODES b
where CATEGORY='Front End'
-- 두 비트가 모두 1일 때만 1을 반환
-- 즉, 해당하는 스킬이 없으면 0을 반환 
and (a.SKILL_CODE & b.CODE)
order by ID