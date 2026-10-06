select a.machine_id , round(avg(b.timestamp - a.timestamp) ,3)as processing_time
from activity a
inner join activity b on 
a.machine_id = b.machine_id
where a.activity_type = 'start' AND b.activity_type ='end'
group by b.machine_id