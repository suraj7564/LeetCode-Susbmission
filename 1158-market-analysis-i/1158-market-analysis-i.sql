# Write your MySQL query statement below
SELECT Users.user_id as buyer_id,join_date,IFNULL(count(Orders.buyer_id),0) AS orders_in_2019 from Users Left JOIN Orders
ON Users.user_id=Orders.buyer_id AND YEAR(Orders.order_date)=2019
group by Users.user_id