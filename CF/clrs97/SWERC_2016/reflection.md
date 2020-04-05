# SWERC 2016

## 3 签到题 想法题 

C

K



## 0 银牌

F. Performance Review

按权值排序之后树状数组维护dfs序即可。

H. Pascal's Hyper-Pyramids

等价于找D个非负整数x1,x2,...,xD，且和为H−1，答案为(H−1)!/x1!x2!...xD!。

考虑爆搜，加上xi≤xi+1以及可行性剪枝即可，计算答案可以分解质因数。

## 5 金牌

B. Bribing Eve

枚举经过1号点的所有直线，统计直线右侧的点数，旋转卡壳即可。

D. Dinner Bet

f[i][j][k]表示有i个仅属于第一个人的数字被选中，j个仅属于第二个人的数字被选中，k个属于两个人的数字被选中的期望次数。

E. Passwords

建立AC自动机，f[i][j][x][y][z]表示串长为i，目前走到了j这个点，小写字母/大写字母/数字是否出现的方案数。

I. The White Rabbit Pocket Watch

在模13意义下高斯消元求出每条边的长度，然后floyd即可。

G. Cairo Corridor

找出与四个边界都连通的连通块，然后枚举连通块里每个点，如果它不是割点，且去掉它之后剩余部分依旧与四个边界都连通，则无解。

## 捧杯
A 几何
J