select distinct author_id AS id
from views
where viewer_id = author_id
order by id ASC;