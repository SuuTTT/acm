# 知识点 - Stirling数



## 解决问题类型：

1. 将p个物体排成k个圆排列(非空循环排列)的方法数。
2. 从左往右会依次遇到A个比当前遇到的最大值更大的元素的排列的个数。（等价于上面的问题）
3. 表示将n个不同的元素拆分成k个集合的方案数。
4. 求泰勒展开系数
5. 每条边的长度为1，对每个节点u，求$E_u = \sum_{v=1}^n (d(u, v))^k,$
6. 从n≤1e9个人中选取一个非空子集X，求所有可能的子集大小的次方之和即$|X|^k$，k≤5000（也可以二项式求导）

## 定义与结论：



### 第一类Stirling数  



1. 多项式$\left\lbrack x \right\rbrack_{n} = x\left( x - 1 \right)\left( x - 2 \right) \cdot \cdot \cdot \left( x - n + 1 \right)$中常数项和$x,x^{2},x^{3}, \cdot \cdot \cdot ,x^{n}$的系数称为**带符号第一类Stirling数**，记为$S_{s}\left( n,k \right),k = 0,2, \cdot \cdot \cdot ,n$. 或$\begin{bmatrix} n \\ k \end{bmatrix}.$

   相对的**无符号的第一类Stirling数**，记为$S_{u}\left( n,k \right)$.对应$\left\lbrack x \right\rbrack_{n} = x\left( x + 1 \right)\left( x + 2 \right) \cdot \cdot \cdot \left( x + n - 1 \right)$

   

2. $S_s$满足递归关系
   $$
   \left\{ \begin{matrix}
   S_{1}\left( n + 1,k \right) = S_{1}\left( n,k - 1 \right) + nS_{1}\left( n,k \right),n \geq 0,k > 0 \\
   S_{1}\left( n,n \right) = 1,S_{1}\left( n,0 \right) = 0 \\
   \end{matrix} \right.\
   $$
   $ $

   $S_u\ $满足递归关系
   $$
   \left\{ \begin{matrix}
   S_{1}\left( n + 1,k \right) = S_{1}\left( n,k - 1 \right) - nS_{1}\left( n,k \right),n \geq 0,k > 0 \\
   S_{1}\left( n,n \right) = 1,S_{1}\left( n,0 \right) = 0 \\
   \end{matrix} \right.\ 
   $$
   

3. $S_u(p,k)$的一个的组合学解释是：将p个物体排成k个圆排列(非空循环排列)的方法数。

   考虑第n+1个物品，如果它单独构成一个圆排列有$S_1(n,k-1)$个方案，插入任意元素的左边有 $nS_1(n,k)$个方案。

4. $$
   \sum_{k=0}^n \begin{bmatrix} n \\ k \end{bmatrix} = n!,
   $$

   

```cpp
s[0][0]=1;
for (register int i=1;i<maxn;++i) {
        for (register int j=1;j<=i;++j) {
            s[i][j]=(s[i-1][j-1]+((i-1)*s[i-1][j])%q)%q;
        }
    }
```



### 第二类Stirling数



1. 多项式$\left\lbrack x \right\rbrack_{n} = x\left( x - 1 \right)\left( x - 2 \right) \cdot \cdot \cdot \left( x - n + 1 \right)$，$x^{n} = \sum_{k = 0}^{n}{S_{2}\left( n,k \right)\left\lbrack x \right\rbrack_{k}}$，称$S_{2}\left( n,k \right)$为第二类Stirling数。记为$\begin{Bmatrix} n \\ k \end{Bmatrix}.$

2. ​	组合学解释是:表示将n个不同的元素拆分成k个集合的方案数。

3. 第二类Stirling数满足$S_{2}\left( n,k \right) = \frac{1}{k!}\sum_{i = 0}^{k - 1}{\left( - 1 \right)^{i}C_{k}^{i}\left( k - i \right)^{n}}$

4. 第二类Stirling数满足递归关系
   $$
   \left\{ \begin{matrix}
   S_{2}\left( n+1,k \right) = S_{2}\left( n,k - 1 \right) + kS_{2}\left( n,k \right),n \geq 0,k \geq 1 \\
   S_{2}\left( 0,0 \right) = 1,S_{2}\left( n,0 \right) = 0 \\
   \end{matrix} \right.\ 
   $$
   $$

5. 第二类Stirling数可以用卷积的方法求，根据（2）得 $S_2(n,k)=\sum_{i=0}^{k-1}\frac{(-1)^i}{i!}\frac{(k-i)^n}{(k-i)!}$ ，对 $a_i=\frac{(-1)^i}{i!}$ 与 $b_i=\frac{i^n}{i!}$ 卷积即可

6. $$
   \sum_{k=0}^n \begin{Bmatrix} n \\ k \end{Bmatrix} = B_n,
   $$

   其中Bn是 [Bell 数](https://en.wikipedia.org/wiki/Bell_number)。

   



### 斯特林数与阶乘幂

我们定义下降幂（Falling Factorial）：
$$
x^{\underline{n}} = x(x-1)\cdots (x-n+1).
$$
以及上升幂（Rising Factorial）：
$$
x^{\overline{n}} = x(x+1)\cdots (x+n-1).
$$
则有以下等式，即上面的定义：
$$
\begin{aligned} x^{\underline{n}} = \sum_{k=0}^n (-1)^{n-k} \begin{bmatrix} n \\ k \end{bmatrix} x^k  & \Longleftrightarrow x^n = \sum_{k=0}^n \begin{Bmatrix} n \\ k \end{Bmatrix} x^{\underline{k}} \\ x^{\overline{n}} = \sum_{k=0}^n \begin{bmatrix} n \\ k \end{bmatrix} x^k  & \Longleftrightarrow x^n = \sum_{k=0}^n (-1)^{n-k} \begin{Bmatrix} n \\ k \end{Bmatrix} x^{\overline{k}} \\ x^{\overline{n}} = \sum_{k=0}^n L(n, k) x^{\underline{k}}  & \Longleftrightarrow x^{\underline{n}} = \sum_{k=0}^n (-1)^{n-k} L(n, k) x^{\overline{k}}  \end{aligned}
$$
其中：
$$
L(n, k) = \sum_j \begin{bmatrix} n \\ j \end{bmatrix} \begin{Bmatrix} j \\ k \end{Bmatrix} = \binom{n-1}{k-1} \frac {n!} {k!}.
$$
注：最常用的是将$x^n$分成若干个$x^{\underline{k}}$之和，或者是$\binom{x}{k}$之和，即
$$
x^n = \sum_{k=0}^n \begin{Bmatrix} n \\ k \end{Bmatrix} x^{\underline{k}} = \sum_{k=0}^n k! \begin{Bmatrix} n \\ k \end{Bmatrix} \binom{x}{k}.
$$


### stirling 反演

斯特林数和阶乘幂的关系可推广至一般函数：
$$
\begin{aligned} g(n) = \sum_{k=0}^n (-1)^{n-k} \begin{bmatrix} n \\ k \end{bmatrix} f(k)  & \Longleftrightarrow f(n) = \sum_{k=0}^n \begin{Bmatrix} n \\ k \end{Bmatrix} g(k) \\ g(n) = \sum_{k=0}^n L(n, k) f(k) & \Longleftrightarrow f(n) = \sum_{k=0}^n (-1)^{n-k} L(n, k) g(k)  \end{aligned}
$$

### 第一类斯特林数的快速求解

为快速计算$\begin{bmatrix} n \\ k \end{bmatrix}$，我们利用
$$
x^{\overline{n}} = \sum_{k=0}^n \begin{bmatrix} n \\ k \end{bmatrix} x^k.
$$
令$f(x) = x^{\overline{n}}, g(x) = (x+n)^{\overline{n}}$,则 $f(x)g(x) = x^{\overline{2n}}$。这样我们就能从$\begin{bmatrix} n \\ k \end{bmatrix}$ 得到$\begin{bmatrix} 2n \\ k \end{bmatrix}$ .

计算过程如下，设：
$$
f(x) = \sum_{k=0}^n a_k x^k,
$$
则：
$$
\begin{aligned} g(x) & = \sum_{k=0}^n a_k (x+n)^k \\ & = \sum_{k=0}^n a_k \sum_{i=0}^k \binom{k}{i} n^{k-i} x^i \\ & = \sum_{k=0}^n \frac{1} {(n-k)!} x^{n-k} \sum_{i+j=k} \frac{n^i}{i!} a_{n-j} (n-j)! \end{aligned}
$$
就变成了卷积计算。每一次倍增用快速傅里叶变换则计算g(x)的时间复杂度为O(nlogn)。

总复杂度为$T(n) = T(n/2)+O(n\log n)=O(n\log n)$

### reference:

证明：[百度百科]([https://baike.baidu.com/item/%E6%96%AF%E7%89%B9%E6%9E%97%E6%95%B0/4938529?fr=aladdin](https://baike.baidu.com/item/斯特林数/4938529?fr=aladdin))   公式：[![返回主页](https://www.cnblogs.com/Skins/custom/images/logo.gif)](https://www.cnblogs.com/TinyWong/)[liouzhou_101](https://www.cnblogs.com/TinyWong/p/10435831.html)



## 复杂度：

递推的话是$O(n^2)$

注意到第二类stirling数可以卷积,用FFT $O(nlogn)$

第一类也可以构造出卷积，$O(nlogn)$



## 例题

[Count the Buildings](http://acm.hdu.edu.cn/showproblem.php?pid=4372)给你一个n，表示有n个高度分别为1，2，3……n的楼，然后要求你排列这n个楼的位置，使得从最左端看能看到x个楼，从最右端看到y个楼，问你满足要求的方案数。

解：先将最高的楼去掉，然后将剩下的n-1个楼分成x-1+y-1组，每组内部是随意排列的，而组之间要保证从左/右往中间是递增的，这就是第一类斯特林数的定义。在中x-1+y-1组中选x-1个放在左边，得到公式：
$$
S(n-1,x-1+y-1)*C(x-1+y-1,x-1)
$$
exe

[CodeForces 932E. Team Work](https://www.cnblogs.com/TinyWong/p/10436347.html)从n≤1e9个人中选取一个非空子集X，求所有可能的子集大小的次方之和即$|X|^k$，k≤5000

[HDU 4625. JZPTREE](https://www.cnblogs.com/TinyWong/p/10436473.html)每条边的长度为1，对每个节点u，求$E_u = \sum_{v=1}^n (d(u, v))^k,$

[CodeForces 1097G. Vladislav and a Great Legend](https://www.cnblogs.com/TinyWong/p/10436870.html)类似上一题

[CodeForces 960G. Bandit Blues](https://www.cnblogs.com/TinyWong/p/10438986.html)类似例题

[Coefficient](http://acm.hdu.edu.cn/showproblem.php?pid=6593)hdu多校求泰勒展开系数，dls说有用到stirling数

## 代码

```cpp

using namespace std;
typedef long long giant;
const int maxn=2e3+1;
const giant q=1e9+7;
giant c[maxn][maxn],s[maxn][maxn];
int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.in","r",stdin);
    #endif
    c[0][0]=s[0][0]=1;
    for (register int i=1;i<maxn;++i) {
        c[i][0]=1;
        for (register int j=1;j<=i;++j) {
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%q;
            s[i][j]=(s[i-1][j-1]+((i-1)*s[i-1][j])%q)%q;
        }
    }
    int T=read();
    while (T--) {
        int n=read(),f=read(),b=read();
        giant ans=(c[b+f-2][b-1]*s[n-1][b+f-2])%q;
        printf("%lld\n",ans);
    }
}
```

