

select a.contest_id , 
        ROUND(
        COUNT(b.user_id) * 100.0 /
        (SELECT COUNT(*) FROM users),
        2
    ) AS percentage
from register a 
inner join users b on 
a.user_id = b.user_id
group by a.contest_id
order by percentage DESC , a.contest_id ASC
