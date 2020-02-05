# concrete mathmatics

## 1 递归recurrent problems

### 1.1 Hanoi

​			解题步骤：

1. look at small cases

2. name and conquer

   

   充要条件都要证明:

   $T_n\le 2T_{n-1} + 1$ 

   $T_n\ge 2T_{n-1} + 1$ 

解题一般步骤

1 Look at small cases. This gives us insight into the problem and helps us
in stages 2 and 3.
2 Find and prove a mathematical expression for the quantity of interest. 
For the Tower of Hanoi, this is the recurrence (1.1) that allows us, given
the inclination, to compute Tn for any n.
3 Find and prove a closed form for our mathematical expression. For the
Tower of Hanoi, this is the recurrence solution (1.2).

### 1.2 Line in Plane

一条直线最多将一个凸包分成两个凸包。

一条直线能分割n个凸包当且仅当它交于n-1条边。（hdu多校#9的1002区域数==交点数+1  $V-E+F = 2$）

## 1.3Josephus porblem

对于每两个人杀一个的递推式：

J(1) = 1 ;
J(2n) = 2J(n) - 1 ; for n >= 1;
J(2n + 1) = 2J(n) + 1 ; for n >= 1.

n 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
J(n) 1 1 3 1 3 5 7 1 3 5 7 9 11 13 15 1

repertoire method：待定系数+待定函数法？？