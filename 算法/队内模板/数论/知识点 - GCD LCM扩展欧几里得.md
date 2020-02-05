# 知识点 - GCD LCM 与 扩展欧几里得





## 解决问题类型：

1. 如何求出方程的解：

$$
ax+by=c
$$

​	推论：求模数非质数但互质的逆元



## 结论：

**2.4.1 定理** 上述方程有解的充要条件是 $gcd(a,b)|c$ （$c$ 是 $gcd(a,b)$ 的倍数）

可以理解为，$gcd(a,b)$ 是 $ax+by$ 可以表示出的最小正整数

**2.4.2 定理** 方程 $ax+by=d,d=gcd(a,b)$ 的所有解为
$$
\begin{cases}
x=x_0+\frac{b}{d}t\\
y=y_0-\frac{a}{d}t
\end{cases}
$$
其中 $x_0,y_0$ 是一组特解

**2.4.3 定理** 方程 $ax+by=c,gcd(a,b)|c$ 的所有解为
$$
\begin{cases}
x=\frac{c}{d}x_0+\frac{b}{d}t\\
y=\frac{c}{d}y_0-\frac{a}{d}t
\end{cases}
$$
其中 $x_0,y_0$ 是方程 $ax+by=d,d=gcd(a,b)$ 的一组特解

```cpp

ll ext_gcd(ll a,ll b,ll& x,ll& y){
    ll d = a;
    if (!b){
        x = 1;y = 0;
    }else{
        d = ext_gcd(b,a%b,y,x);
        y -= a/b*x;
    }
    return d;
}
```



在求逆元时，要找到 $b^{-1}$ 使得 $bb^{-1}\equiv 1(mod\ c)$ ，实质上是求解方程 $bx+cy=1$ 中的 $x$ ，因此可以用扩展欧几里得算法来求逆元，当然只有 $gcd(b,c)=1$ 时才有解，否则逆元不存在。注意10x=14(mod 22) 等价于 5x=7(mod 11) 





###### 附gcd性质：

**2.1.1 性质** $gcd(a,b)=gcd(b,a)$

**2.1.2 性质** $gcd(a,b)=gcd(a-b,b)(a\ge b)$

**2.1.3 性质** $gcd(a,b)=gcd(a\%b,b)$  

**2.1.4 性质** $gcd(a,b,c)=gcd(gcd(a,b),c)$  

**2.1.5 性质** $gcd(ka,kb)=k\ gcd(a,b)$

```cpp
typedef long long ll;
ll gcd(ll a, ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
```


$$
lcm(a,b)=\frac{ab}{gcd(a,b)}
$$


## 复杂度：

 $O(\log \min(a, b))$.最坏情况的输入是斐波那契数列的相邻项。

## 例题

#### [A/B](http://acm.hdu.edu.cn/showproblem.php?pid=1576)

要求(A/B)%9973，但由于A很大，我们只给出n(n=A%9973)(我们给定的A必能被B整除，且gcd(B,9973) = 1)。

###### 练习：

- [10104 - Euclid Problem](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045)
- [GYM - (J) Once Upon A Time](http://codeforces.com/gym/100963)
- [UVA - 12775 - Gift Dilemma](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4628)

## 代码

```cpp
//原题等价于求 mod 9937 意义下的逆元。注意到9937非质数，gcd(B,9973) = 1。选择使用扩展欧几里得求逆元
#include<stdio.h>
#define MOD 9973
//******************************
//返回d=gcd(a,b);和对应于等式ax+by=d中的x,y
long long extend_gcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0){x=1;y=0;return a;}
    long long d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
//*********求逆元素*******************
//ax = 1(mod n)
long long mod_reverse(long long a,long long n)
{
    long long x,y;
    long long d=extend_gcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
}

int main()
{
    int T;
    int n,B;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&B);
        int x=mod_reverse(B,MOD);
        printf("%d\n",n*x%MOD);
    }
    return 0;
}
```





