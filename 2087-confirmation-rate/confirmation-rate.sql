select a.user_id, round(AVG(CASE WHEN action = 'confirmed' THEN 1.0 ELSE 0 END),2) AS confirmation_rate
from signups a
left join confirmations b on 
a.user_id = b.user_id
group by a.user_id
