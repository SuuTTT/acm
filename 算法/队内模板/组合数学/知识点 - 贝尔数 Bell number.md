# 知识点 - 贝尔数 Bell number



## 解决问题类型：





## 定义：

[wiki](http://wikipedia.moesalih.com/Bell_number#Set_partitions)   [A000110](http://oeis.org/A000110)

集合划分的方案数。即问n个不同物体，分成若干集合（集合没有区别）的方案数。

```cpp
1, 1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975, 678570, 4213597, 27644437, 190899322, 1382958545, 10480142147, 82864869804, 682076806159, 5832742205057,
```

### 公式

$$
B_{n+1}=\sum_{k=0}^n\binom{n}{k}B_k
$$

图解：

### ![Bell_numbers_subset_partial_order.svg](C:\Users\acm-14\Desktop\workplace\graph\Bell_numbers_subset_partial_order.svg.png)

### Rhyme schemes

[Rhyme schemes](https://nanti.jisuanke.com/t/41414)

![1568601160094](C:\Users\acm-14\AppData\Roaming\Typora\typora-user-images\1568601160094.png)

长度为n的Rhyme schemes的方案数为$B_n$

询问字典序第k小的rhyme schemes

 AAAA, AAAB, AABA, AABB, AABC, ABAA, ABAB, ABAC, ABBA, ABBB, ABBC, ABCA, ABCB, ABCC, and ABCD

```cpp
//输入n，k,问长度为n的Rhyme schemes中字典序第k小的是什么
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(ll i = (ll)j;i <= (ll)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define pb push_back
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0)
const ll INF = (ll)(1e18);
const ll mod = 1000000007;
int n;
__int128 k;
__int128 x[30][30];
__int128 dfs(int num,int has){
    if(x[num][has]>=0)return x[num][has];
    __int128 w=dfs(num-1,has);
    __int128 ww=dfs(num-1,has+1);
    //debug(w);debug(ww);
    //debug(num);debug(has);debug(w*has+ww);
    return x[num][has]=w*has+ww;
}
template <class T>
void read(T &x) {
	static char ch;static bool neg;
	for(ch=neg=0;ch<'0' || '9'<ch;neg|=ch=='-',ch=getchar());
	for(x=0;'0'<=ch && ch<='9';(x*=10)+=ch-'0',ch=getchar());
	x=neg?-x:x;
}
int main()
{
    for(int i=0;i<=26;i++)
        for(int j=0;j<26;j++)x[i][j]=-1;
    for(int i=0;i<=26;i++)x[0][i]=1;
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d",&n);
        read(k);
        string ans="A";
        int h=1;
        for(int i=1;i<n;i++){
            __int128 f=dfs(n-i-1,h);
            //debug(f);
            if(k>f*h){
                k-=f*h;
                ans+=h+'A';
                h++;
            }
            else {
                __int128 g=(k-1)/f;
                ans+=g+'A';
                k-=g*f;
            }
            //debug(ans);
            //debug(h);
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
	return 0;
}
/*
*/

```



## 例题

[Gugugu's upgrade sch emes @ 沈阳网络赛](https://nanti.jisuanke.com/t/41405)

首先容易看出这个数是集合的划分数，即贝尔数，对于贝尔数的预处理一般需要O（n²）的复杂度，显然对于题目里的数据范围是不合适的，但是我们观察到模数是一个小于1000的质数，以此为突破口，如果知道Touchard同余的话这题就迎刃而解了，Touchard同余简而言之就是当p为质数时 ，这样我们可以预
处理出小于p的贝尔数，然后可以通过记忆化的方式去搜索，因为考虑到递归过深可能爆栈，故此题限制n/p<1000.