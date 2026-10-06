select a.name
from employee a
inner join employee b on 
a.id = b.managerId
group by a.id
having count(*) >= 5