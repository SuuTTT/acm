# 知识点 - Catalan数



## 解决问题类型：

1.由n个+1和n个-1组成的排列中，满足前缀和>=0的排列有Catalan(N)种。

2.括号化问题。左括号和右括号各有n个时，合法的括号表达式的个数有Catalan(N)种。

3.有n+1个数连乘，乘法顺序有Catalan(N)种,相当于在式子上加括号。

4.n个数按照特定顺序入栈，出栈顺序随意，可以形成的排列的种类有Catalan(N)种。即可以被栈排序(stack sort)的排列数。

5.给定N个节点，能构成Catalan(N)种种形状不同的二叉树。（左节点标+1,右结点-1）

6.n个非叶节点的满二叉树的形态数为Catalan(N)。

7.对于一个n*n的正方形网格，每次只能向右或者向上移动一格，那么从左下角到右上角的不同种类有Catalan(N)种。

8.对于在n位的2进制中，有m个0，其余为1的catalan数为：C（n,m）-C(n,m-1)。

9.对凸n+2边形进行不同的三角形分割（只连接顶点对形成n个三角形）数为Catalan(N)。

10.将有2n个元素的集合中的元素两两分为n个子集，若任意两个子集都不交叉，那么我们称此划分为一个不交叉划分。此时不交叉的划分数是Catalan(N)。

11.用n个长方形去填充一个高度为n的阶梯图形的方法数。

12.在一个2*n的格子中填入1到2n这些数值使得每个格子内的数值都比其右边和上边的所有数值都小的情况数也是Catalan(N)。

### reference

证明：论文[Catalan Number by Tom Davis](http://www.geometer.org/mathcircles/catalan.pdf)， [blog](http://lanqi.org/skills/10939/) ，[代码](https://blog.csdn.net/zuzhiang/article/details/77966726)

## 公式：

（1）Catalan数满足递推方程$C_{n} = \sum_{k = 0}^{n - 1}{C_{k}C_{n - k-1}},n \geq 2;C_{0} = C_{1} = 1$

（2）前几个Catalan数为1,1,2,5,14,42,132,429,1430,4862

（3）Catalan数的通项公式为$C_{n} = \frac{C_{2n}^{n}}{n + 1} = C_{2n}^{n} - C_{2n}^{n - 1}$

（4）Catalan数的另一个递推公式为$C_{n} = \frac{4n - 2}{n + 1}C_{n - 1}$

```cpp
//前三十项卡特兰数表
[1,1,2,5,14,42,132,429,1430,4862,16796,58786,
 208012,742900,2674440,9694845,35357670,129644790,
 477638700,1767263190,6564120420,24466267020,
 91482563640,343059613650,1289904147324,
 4861946401452,18367353072152,69533550916004,
 263747951750360,1002242216651368,3814986502092304]
```

```c++
const int C_maxn = 1e4 + 10;
LL CatalanNum[C_maxn];
LL inv[C_maxn];
inline void Catalan_Mod(int N, LL mod)
{
    inv[1] = 1;
    for(int i=2; i<=N+1; i++)///线性预处理 1 ~ N 关于 mod 的逆元
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;

    CatalanNum[0] = CatalanNum[1] = 1;

    for(int i=2; i<=N; i++)
        CatalanNum[i] = CatalanNum[i-1] * (4 * i - 2) %mod * inv[i+1] %mod;
}
```

```cpp
//卡特兰大数模板
#include<bits/stdc++.h>
using namespace std;
const int C_maxn = 100 + 10;///项数

int Catalan_Num[C_maxn][1000];///保存卡特兰大数、第二维为具体每个数位的值
int NumLen[C_maxn];///每个大数的数长度、输出的时候需倒序输出

void catalan() //求卡特兰数
{
    int i, j, len, carry, temp;
    Catalan_Num[1][0] = NumLen[1] = 1;
    len = 1;
    for(i = 2; i < 100; i++)
    {
        for(j = 0; j < len; j++) //乘法
        Catalan_Num[i][j] = Catalan_Num[i-1][j]*(4*(i-1)+2);
        carry = 0;
        for(j = 0; j < len; j++) //处理相乘结果
        {
            temp = Catalan_Num[i][j] + carry;
            Catalan_Num[i][j] = temp % 10;
            carry = temp / 10;
        }
        while(carry) //进位处理
        {
            Catalan_Num[i][len++] = carry % 10;
            carry /= 10;
        }
        carry = 0;
        for(j = len-1; j >= 0; j--) //除法
        {
            temp = carry*10 + Catalan_Num[i][j];
            Catalan_Num[i][j] = temp/(i+1);
            carry = temp%(i+1);
        }
        while(!Catalan_Num[i][len-1]) //高位零处理
        len --;
        NumLen[i] = len;
    }
}

int main(void)
{
    catalan();
    for(int i=1; i<=30; i++){
        for(int j=NumLen[i]-1; j>=0; j--){
            printf("%d", Catalan_Num[i][j]);
        }puts("");
    }
    return 0;
}
```



## 问题复杂度：

## 例题

[Robot](http://acm.hdu.edu.cn/showproblem.php?pid=5673):坐标原点有一个机器人， 这个机器人每次可以选择向左走向右走休息一秒， 但是不能走向负半轴， 现在机器人进过一系列运动之后返回了坐标原点， 问你有多少种情况可以使机器人到达坐标原点。

设向右走了$i$步，则有$C(n,2i)\cdot cat(i) $种方案:n秒中选出2i秒移动，然后是一个括号匹配等价问题。

所以答案为
$$
\Sigma_i C(n,2i)\cdot cat(i)
$$



## 代码

```cpp
//https://www.cnblogs.com/xingxing1024/p/5432676.html
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long LL;
LL M = 1000000007;
const int maxn = 1000000 + 100;
LL nfic[maxn*2], rev_nfic[maxn*2];
LL cata[maxn];

LL qk_mod(LL a, LL b){
    LL res = 1;
    while(b > 0){
        if(b&1)
            res = (res*a)%M;
        a = (a*a)%M;
        b >>= 1;
    }
    return res;
}

LL Com(LL n, LL m){
    LL res = nfic[n];
    res = res*rev_nfic[m]%M;
    res = res*rev_nfic[n-m]%M;
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    nfic[0] = 1;
    rev_nfic[0] = 1;
    for(int i=1; i<=2*1000000+3; i++){
        nfic[i] = (i*nfic[i-1])%M;
        rev_nfic[i] = qk_mod(nfic[i], M-2);
    }
    for(int i=0; i<=1000000; i++){
        cata[i] = Com(2*i, i)*qk_mod(i+1, M-2)%M;
    }
    while(T--) {
        int n;
        scanf("%d", &n);
        LL res = 0;
        for(int i=0; i<=n/2; i++){
            res = (res + Com(n, 2*i)*cata[i])%M;
        }
        cout<<res<<endl;
    }
    return 0;
}
```

