# Write your MySQL query statement below
select u.name, sum(amount) as balance
from Users as u left join Transactions as t
on u.account = t.account
group by u.account
having sum(amount)>10000;