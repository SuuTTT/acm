# ch4 数论

数论研究正数的性质

## 1.整除

\ gcd lcm  扩展欧几里得。

整除求和$\sum_{n|m}$的几个公式。ch2的知识会很有用。

## 2.质数

Fundamental Theorem of Arithmetic：

根据唯一分解定理，每个数可以用质数的次数数组表示：
$$
(n_2,n_3,n_5...)
$$
这样\ gcd lcm都有了新的定义。这种形式后面也会用到

## 3.质数example

### 欧几里得数

#### 定义

根据质数有无数个证明的证明形式得到欧几里得数(Euclid numbers)
$$
e_n = e_1e_2 ... e_{n-1} + 1\\
e_1=1
$$

#### 性质

欧几里得数e1~e5,e6是质数，其它（<=e19）不是。 

根据欧几里得算法欧几里得数互质。

递推式为：
$$
e_n=e^2_{n-1}-e_{n-1}+1
$$
公式为：$E \approx 1.264$是无理数。
$$
e_n=\lfloor E^{2^n}+1/2\rfloor
$$
一个类似的得到质数的公式：
$$
p_n=\lfloor P^{3^n}\rfloor
$$
这样的公式没有实际用途的，因为里面的常数是根据数列推算出来的。

### 梅森数

#### 定义

$2^p-1$的数

### 性质

有特殊的方法进行素数测试。

$2^pk+1$也有一些特殊性质。

### 质数的密度

$P_n \approx n \ln n$

$\pi(x)\approx \frac{x}{\ln x}$

P23 页说n很大时 渐进于 ln ln n，且也代表n的不同质因子数的期望。

## 4.阶乘的近似和质因数分解

指数上的不等式放缩得到阶乘的上下界。

阶乘质因数分解公式

## 5.互质

记$m\perp n$,给出了一些唯一分解定理数组和向量垂直的类比，和性质。

### Stern-Brocot tree

#### 构造与定义：

从$\frac{0}{1},\frac{1}{0}$开始相邻的两个分数分子分母分别相加，得到的数写在它们之间。

把每次迭代得到的新数写在一层中，每一层称Farey series $F_n$

可以得到一棵SB树。

#### 性质：

SB树包含了所有有理数，不重不漏。

可用LR串来代表任意有理数。L代表向左儿子转移，resp.R

知LR串求有理数可以用矩阵转移。

知有理数求LR串可以用二分加转移。



## 6.模 ：一致关系与CRT

这里我们对整个等式取模，$a\equiv b(\mod m) $ 读作a is congruent to b modulo m（同余/全等）. 可以理解为$a-b=km$

模相同下可以下加减乘，除分类讨论：
$$
ad \equiv bd(\mod m )\leftrightarrow a\equiv b(\mod \frac{m}{gcd(d,m)})
$$
模不同可以互相推导：
$$
a \equiv b(\mod md )\rightarrow  a \equiv b(\mod d )
$$

$$
a \equiv b(\mod m ),a \equiv b(\mod n )\rightarrow  a \equiv b(\mod lcm(m,n) )
$$

特别地，当$m\perp n$时，就是CRT的形式。

## 7.CRT应用：独立余

同余的一个应用是 residue number system（余数系统）即把x表示为模一些两两互质的数的余数。
$$
Res(x) = (x \mod m_1, ... , x \mod m_r)  
$$
对余数数组的每个元素分别加减 除（需讨论） 等价于对原数的运算。用CRT得到x



讨论了$x^2\equiv1$的解



例题

[P4139 上帝与集合的正确用法](https://www.luogu.org/problem/P4139)

[hdu多校第六场 1006 Faraway](https://blog.csdn.net/qq_41848675/article/details/98883631)

## 8.一些定理 费马小定理，威尔逊定理

证明了引理
$$
0 \mod m, n \mod m, 2n \mod m, ..., (m- 1)n \mod m\\ consist\ of\  
0, d, 2d, ..., m- d
$$
然后证明了费马小定理
$$
n^{p-1}\equiv 1(\mod p)
$$
用上一节$x^2\equiv1$的结论证明了Wilson's theorem:
$$
(n - 1)! \equiv -1 (mod n)\leftrightarrow \ n\ is\ prime,
$$

## 9.phi 和 mu 积性函数

$\phi(n)$是0~m-1中与m互质的数的数量。gcd（x，0）==x??

### 积性函数

根据定义，尤其再质数处的函数值决定。

$x^2\equiv1$的解的数量也是积性函数。



用分数的最简形式 farey series证明了
$$
\sum_{d|n}\phi(d)=n
$$
证明了g(n)是积性的。
$$
g(n)=\sum_{d|n}\phi(d)
$$

### mu

#### 定义

$$
\sum_{d|n}\mu(d)=[n=1]
$$

#### 性质

莫比乌斯反演

mu(d)的计算

phi前缀和



例题

本质不同的项链种类 polya？？