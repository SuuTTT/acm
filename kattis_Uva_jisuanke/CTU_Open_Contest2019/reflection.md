# 2019 ICPC Malaysia National

## 3 签到题 想法题 

### A ### B

## 0 银牌

### C 圆与长方形交

### F 贪心

### I 贪心+几何

平面上若干个点，这些点同时平移固定量后，与原图像合并，现在已知合并后的图像，求有多少个合法的平移量


## 2 金牌

### E 大模拟

### G 字符串 

G是对给定字符串，选择最长的一个连续子串，要求这个子串重新排列后可以变成回文串，问子串最大长度

### J 18*18*nDP 填字游戏

2*n的网格，n>=3，有些格子已经填了数字，要求填剩余的，保证任何一个2*3区块内的和为k，求方案数。填的数字是digit，应该只能填0-9

### E 编辑距离

E题就是求两个含数字的串的编辑距离：两个串都可以操作，目标是让两个串里没有数字且相等，问最小的操作数。操作有任意位置插入一个字母，删除任意位置的字母，还有把数字x变成长度为x的任意串。

## 捧杯


### 无限量网络流

一个有一个源点和一个汇点的图, 源点有足够的流量，每个点都可以被流过（从源点到达）告诉你每个管子里的流向，问去掉最多的管子使得每个点任然能被流过，且剩下的管子里流向不变。