# ch2 求和

## 1.sigma及相关符号

1. $\sum\limits_{i=1}^{n}i$  是确定式，$\sum\limits_{1\le i\le n}i$是一般式。 一般式进行下标换元不容易出错，确定式写代码的时候好写些。

2. 边界问题：越简单越好。

3. Kenneth E. Iverson括号: $[p\ prime]$  可以用于化简一般式：
   $$
   \sum\limits_{p(k)}a_k=\sum\limits_{k}a_k[p(k)]
   $$
   
4. 值为0的项可以简化求和

## 2.求和与递归

1. 前缀和可以看成一种递归（递推）
   $$
   S_n=S_{n-1}+a_n
   $$
   
2. 插值求出解析式形式。

3. 很多递归可以化为和的形式。比如汉诺塔问题
   $$
   T_n=2T_{n-1}+1\\
   T_n/2^n = T_{n-1}/2^{n-1}+1/2^n\\
   T_n/2^n=\sum\limits2^{-k}
   $$
   注意这个除法技巧可以用于所有一阶递推方程，这里的系数可以带n
   $$
   a_nT_n=b_nT_{n-1}+c_n
   $$
   求了快排的期望比较次数：H_n为调和级数
   $$
   c_n=n+1+2/n\cdot\sum_{k=0}^{n-1}C_k\\
   c_n=2(n+1)H_n=2n
   $$
   

   

   ## 3.求和法则

   1.分配律，结合律和交换律 p(k)指置换
   $$
   \sum_{k\in K}ca_k=c\sum_{k\in K}a_k\\
   \sum_{k\in K}(a_k+b_k)=\sum_{k\in K}a_k+\sum_{k\in K}b_k\\
   \sum_{k\in K}a_k=\sum_{p(k)\in K}a_{p(k)} \\
   $$
   

2.应用：高斯求和的证明。

3.交换律：注意所有的k都要出现一次。

5.不同集合的求和。
$$
\sum_{k\in K}a_k+\sum_{k\in K'}a_k=\sum_{k\in K\and K'}a_k+\sum_{k\in K \or K'}a_k
$$
6.perturbation method 微扰法：分出某些项。比如几何级数（等比数列）求和，差比数列求和证明，分出第一项，使得目标和在等式两边出现。 差比数列也可以求导得到。



## 4.多重求和

1. 基本法则：交换求和顺序
   $$
   \sum_j\sum_ka_{j,k}[P(j,k)]=\sum_{P(j,k)}a_{j,k}=\sum_k\sum_ja_{j,k}[P(j,k)]
   $$
   
2. 两个变型 

   *香草*（vanilla-favored law）,当j,k是独立时有：（即上面的集合版本）
   $$
   \sum_{j \in J}\sum_{k\in K}a_{j,k}=\sum_{j \in J,k\in K}a_{j,k}=\sum_{k\in K}\sum_{j \in J}a_{j,k}
   $$
   

   *石路*(rocky-road formula),当内层求和由外层决定时：
   $$
   \sum_{j \in J}\sum_{k\in K(j)}a_{j,k}=\sum_{k \in K'}\sum_{j\in j'(k)}a_{j,k}\\
   where\  [j \in J][k\in K(j)]=[k \in K'][j\in j'(k)]
   $$
   一个应用是：
   $$
   [1\le j\le n][j\le k\le n]=[1\le j\le k\le n]=[1\le k\le n][1\le j\le k]
   $$
   
3. 例子

   线性求出：
   $$
   \sum_{1\le j\le k\le n}a_ka_j\\
   \sum_{1\le j\lt k\le n}(a_k-a_j)(b_k-b_j)
   $$
   用到了这个性质：
   $$
   [1\le j\le k\le n]+[1\le k\le j\le n]=[1\le j, k\le n]+[1\le j= k\le n]\\
   [1\le j\le k\le n]+[1\le k\le j\le n]=[1\le j, k\le n]-[1\le j= k\le n]
   $$
   以及一个定理：没有在求和项的出现的下标，可以在结果上乘该下标集合的大小，然后去掉这个下标。

   第二个求和公式的结果导出了切比雪夫不等式(Chebyshev's monotonic inequalities，本来是积分形式)。

4. 若f是j到k的满射（一一对应），则有
   $$
   \sum_{j\in J}a_{f(j)}= \sum_{f(j)\in K}a_{f(j)}=\sum_{k\in K}a_k
   $$
   例子：
   $$
   \sum_{1\le j\lt k\le n}\frac{1}{k-j}=nH_n-n
   $$
   

## 5.n^2 前缀和

0.查表 1.归纳 2.高维微扰 3.差值 4.积分 5.双重求和 6.有限积分(finite calculus) 7.生成函数

## 6.微分和差分

1. 定义:微分(Infinite calculus，求导)：
   $$
   Df(x)=\lim_{h\rightarrow 0}\frac{f(x+h)-f(x)}{h}
   $$
   差分(Finite calculus):
   $$
   \Delta f(x)=f(x+1)-f(x)
   $$

2. 下降幂，上升幂（mth power/ "x to the m falling"/falling factorial powers）
   $$
   x^{\underline{n}} = x(x-1)\cdots (x-n+1)\\
   x^{\overline{n}} = x(x+1)\cdots (x+n-1).
   $$
   我们有
   $$
   \Delta x^{\underline{m}}=mx^{\underline{m-1}}
   $$
   和
   $$
   \sum_{0\le k\lt n}k^{\underline{m}}=\frac{n^\underline{m+1}}{m+1}\ if\  m!=-1\\
   else =H_x|_{b}^{a}
   $$
   同时也满足二项式展开，以及幂乘
   $$
   x^{\underline{m+n}}=x^{\underline{m}}(x-m)^{\underline{n}}
   $$
   
3. ![1567513651456](C:\Users\acm-14\AppData\Roaming\Typora\typora-user-images\1567513651456.png)



## 7.无限求和

玄



