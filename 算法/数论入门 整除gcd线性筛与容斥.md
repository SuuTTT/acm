##abstract
 
>线性筛与容斥
线性筛求积性函数 nlogn(Eratosthenes)筛求约数和
欧拉函数性质+代数(求和)变换 求gcd,lcm的和   
$\sum\limits ^{n}_{i=1} i[ gcd( i,n) =1] =\frac{N*\phi (N)}{2}$  
$\sum\limits ^{n}_{i=1}\sum\limits ^{n}_{i=1}[ gcd( i,j) =p]$  
$\sum\limits ^{n}_{i=1} gcd( i,n) \$  
$\sum\limits ^{n}_{i=1}\sum\limits ^{n}_{j=i+1} gcd( i,j)$   
$\sum\limits ^{n}_{i=1}\sum\limits ^{m}_{j=1} gcd( i,j) *2-1$  
莫比乌斯函数求容斥  
倒着更新容斥

##SP5971 || spoj LCM sum


###题意

求 $\sum\limits ^{n}_{i=1} lcm( i,n)$

---

###题解
欧拉函数性质。  
$\sum\limits ^{n}_{i=1} i[ gcd( i,n) =1] =\frac{N*\phi (N)}{2}$  
然后枚举gcd来拆出这个公式，

最后用调和级数筛来算约数求和。

---

###代码



```
#include<algorithm>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#include<math.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string>
#include<ctime>
#include<stack>
#include<map>
#include<set>
#include<list>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
//#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
//#define int long long
#define REP(i,j,k) for(int i = (int)j;i < (int)k;i ++)
#define per(i,j,k) for(int i = (int)j;i >= (int)k;i --)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define mmm(a,b) memset(a,b,sizeof(a))
#define md(x) x=(x+mod)%mod
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define precise(x) fixed << setprecision(x)
typedef long long ll;

const int N = 1e6+9;
int lp[N + 1];
int mu[N + 1],vis[N+1];

vector<int> pr;


int phi[N+1];
ll ans[N + 1];
void sieve_phi() {
	phi[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			phi[i] = i - 1;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j)
		{
			lp[i * pr[j]] = pr[j];
			if (i%pr[j])phi[i*pr[j]] = phi[i] * (pr[j] - 1);
			else phi[i*pr[j]] = phi[i] * pr[j];
		}
	}
	rep(i, 1, N) {
		for (int j = 1; i*j <= N; j++) {
			ans[i*j] += (i == 1 ? 1 : 1ll * phi[i] * i / 2);
		}
	}
}


int main() {
	sieve_phi();
	int t; cin >> t;
	while (t--) {
		int x;
		cin >> x;
		cout << ans[x] * 1ll*x << endl;
	}
	//cin >> t;
}


```

---

###心路历程

```

```

---


##P2568 or BZOJ2568  GCD

###题意
$\sum\limits ^{n}_{i=1}\sum\limits ^{n}_{i=1}[ gcd( i,j) =p]$
求1~n内有多少有序对gcd(x,y)是素数  


---

###题解
发现gcd(x,y)==1的对数是phi的前缀和-1。  
所以我们对每个素数p，在gcd(x,y)=p两边除掉p来凑形式。  



---

###代码



```
typedef long long ll;

const int N = 1e7+9;
int lp[N + 1];


vector<int> pr;


ll phi[N+1];
ll ans[N + 1];
void sieve_phi() {
    phi[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j)
        {
            lp[i * pr[j]] = pr[j];
            if (i%pr[j])phi[i*pr[j]] = phi[i] * (pr[j] - 1);
            else phi[i*pr[j]] = phi[i] * pr[j];
        }
    }
    rep(i, 1, N) {
        phi[i] = phi[i - 1] + phi[i];
    }
}


int main() {
    sieve_phi();
    int n;
    cin >> n;
    ll ans = 0;
    for (int j = 0; j < (int)pr.size() && pr[j] <= n; j++)
        ans += phi[n / pr[j]] * 2ll - 1ll;
    cout << ans << endl;
    cin >> n;
}


```

---

###心路历程

```

```

---
##P4318 完全平方数 || BZOJ 2440

###题意
求第k大的无平方因子数


---

###题解
先二分，猜一个数，判它是第几大。
判的算法：
考虑和莫比乌斯mu的关系。  
对于某个数i，对答案的贡献是n/i^2。
而mu就是容斥符号。  



---

###代码



```
const int N = 1e6+9;
int lp[N + 1];


vector<int> pr;


ll phi[N+1];
ll ans[N + 1];
int mu[N + 1];
void sieve_phi() {
	phi[1] = 1;
	mu[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			phi[i] = i - 1;
			mu[i] = -1;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j)
		{
			lp[i * pr[j]] = pr[j];
			if (i%pr[j]!=0)phi[i*pr[j]] = phi[i] * (pr[j] - 1), mu[i*pr[j]] = -mu[i];
			else phi[i*pr[j]] = phi[i] * pr[j];
		}
	}
}
ll order(ll x) {
	ll ret = 0;
	for (ll i = 1; i*i <= x; i++)ret += mu[i] * (x / (i*i));
	return ret;
}

int main() {
	sieve_phi();
	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		ll l=1, r=k<<1;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (order(mid) >= k)r = mid-1;
			else l = mid + 1;
		}
		cout << l << endl;
	}
	
	cin >> n;
}
/*
4
1
13
100
1234567
*/


```

---

###心路历程

```

```

---
##POJ2480
###题意
$\sum\limits ^{n}_{i=1} gcd( i,n) \$


---

###题解

原式=$\sum\limits _{d|n} phi( d) *\frac{d}{n}$
这样暴力搜约数就能过了，  
不过还有更快的，[狂推公式](https://www.cnblogs.com/xiaowuga/p/7161513.html)   

```
n>1时 n=p1^a1*p2^a2*...*ps^as，p为n的质因子， 
那么f(n)是积性函数的充要条件是f(1)=1，及f(n) = f(p1^a1)*f(p2^a2)*...f(pr^ar)，所以只要求f(pi^ai)就好。  


f(pi^ai) =  Φ（pi^ai）+pi*Φ（pi^(ai-1)）+pi^2*Φ（pi^(ai-2)）+...+pi^(ai-1)* Φ（pi）+ pi^ai *Φ（1）

根据性质1，我们可以做出如下化简

f(pi^ai)=[pi^(ai-1)*(pi-1) ] +  [pi*pi^(ai-2)*(pi-1)]  +  [pi^2*pi^(ai-3)*(pi-1)]  +  [pi^3*pi^(ai-4)*(pi-1)]....[pi^(ai-1)*pi^(ai-ai)*(pi-1)]+pi^ai   ①

然后对①提取公因子（pi-1）

f(pi^ai)=(pi-1){[pi^(ai-1) ] +  [pi*pi^(ai-2)]  +  [pi^2*pi^(ai-3)]  +  [pi^3*pi^(ai-4)]....[pi^(ai-1)*pi^(ai-ai)]+[pi^ai/(pi-1)]}  ②

紧接着我们发现出了最后一项每个[]每个方括号内乘积都等于pi^(ai-1),所以对②提取公因子pi^(ai-1)

f(pi^ai)=(pi-1)*pi^(ai-1)*{ai+[pi/(pi-1)]} ③

然后把(pi-1)/pi放进括号里得

f(pi^ai)=pi^(ai)*{1+ai*(pi-1)/pi} ④

这个 ④是单个f(pi^ai)的公式，我们提取所有的pi^(ai)相乘实际上就是n了，所以我们可以得到f(n)的公式：f(n)=n*∏（1+ai*(pi-1)/pi）
```

---

###代码



```
typedef long long LL;
LL euler(LL n){
    LL res=n;
    for(LL i=2;i*i<=n;i++){
        if(n%i==0){
            res=res/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1)  res=res/n*(n-1);
    return res;
}
int main(){
    LL n;
    while(scanf("%lld",&n)!=EOF){
        LL ans=0;
        for(LL i=1;i*i<=n;i++){
            if(n%i==0){
                ans+=euler(n/i)*i;
                if(i*i<n) ans+=euler(i)*(n/i);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}


```

```
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    while(cin>>n){
        LL i,sqr,p,a,ans;
        ans=n;
        sqr=floor(sqrt(1.0*n));
        for(int i=2;i<=sqr;i++){
            if(n%i==0){
                a=0;p=i;
                while(n%p==0){
                    a++;n/=p;
                }
                ans=ans+ans*a*(p-1)/p;
            }
        }
        if(n!=1) ans=ans+ans*(n-1)/n;
        cout<<ans<<endl;
    }        
    return 0;
}
```

---

###心路历程

```
代数好差orz 根本看不出形式
```

---
##UVA - 11426  

###题意

$\sum\limits ^{n}_{i=1}\sum\limits ^{n}_{j=i+1} gcd( i,j)$  

---

###题解

上一题的弱化版套一个前缀和。  
因为n的取值变小了，所以$\sum\limits _{d|n} phi( d) *\frac{d}{n}$可以用log筛了,


---

###代码



```
//头文件省略
const ll N = 4e6 ;

ll g[N + 1];
ll s[N + 1];

int lp[N + 1];
vector<int> pr;
ll phi[N + 1];
ll ans[N + 1];
int mu[N + 1];
void sieve_phi() {
	phi[1] = 1;
	mu[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			phi[i] = i - 1;
			mu[i] = -1;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j)
		{
			lp[i * pr[j]] = pr[j];
			if (i%pr[j] != 0)phi[i*pr[j]] = phi[i] * (pr[j] - 1), mu[i*pr[j]] = -mu[i];
			else phi[i*pr[j]] = phi[i] * pr[j];
		}
	}
}
void init() {
	rep(i, 1, N)
		for (int j = 1; j*i <= N; j++)
			//g[j*i] +=(i==1?1: phi[i] * j);
			g[j*i] += phi[i] * j;
	s[2] = g[2]-2;
	rep(i, 3, N)g[i] -= i, s[i] = s[i - 1] + g[i];
}
int main() {

	ll n;
	sieve_phi();
	init();
	while (cin >> n) {
		if (n == 0)break;
		cout << s[n]<<endl;
	}


}

```

---

###心路历程

```
i<j 没注意，QAQ

```

---

##P1447 [NOI2010]能量采集  

###题意
$\sum\limits ^{n}_{i=1}\sum\limits ^{m}_{j=1} gcd( i,j) *2-1$


---

###题解  

按套路枚举所有gcd D，计算gcd(i,j)=D的(i,j)对，记作f[n]  
$\sum\limits ^{n}_{d=1}\sum\limits ^{n}_{i=1}\sum\limits ^{m}_{j=1}[ gcd( i,j) =d] *( 2d-1)$  
f[n]的用容斥，[实现](https://kelin.blog.luogu.org/solution-p1447)是倒着更新


---

###代码



```
//头文件省略


ll n, m;
ll f[N];
void init(){
	per(i, n, 1) {
		f[i] = (n / i)*(m / i);
		for (int j = 2; j*i <= n; j++) {
			f[i] -= f[i*j];
		}
	}

}
int main() {
	cin >> n >> m;
	
	if (n > m)swap(n, m);
	init();
	ll ans = 0;
	rep(i, 1, n) {
		ans += f[i]*(2*i-1);
	}
	cout << ans << endl;;
	cin >> n;
}
```

---

###心路历程

```
orz

```

---



 
##P2522 BZOJ2301 1695 Problem b

###题意



---

###题解



---

###代码



```
//头文件省略


```

---

###心路历程

```

```

---