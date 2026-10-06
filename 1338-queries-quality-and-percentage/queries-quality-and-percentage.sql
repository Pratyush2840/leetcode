
select a.query_name ,   round(sum(a.rating / a.position)/count(query_name) , 2) as quality , 
round(sum(case when a.rating < 3  then 1 else 0 end) * 100/count(query_name),2) as poor_query_percentage

from queries a
group by a.query_name

