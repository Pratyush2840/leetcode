select a.product_id , coalesce( ROUND(SUM(a.price * b.units) / SUM(b.units), 2) , 0) AS average_price
from prices a
left join unitsSold b on
a.product_id = b.product_id
AND b.purchase_date BETWEEN a.start_date AND a.end_date
group by a.product_id