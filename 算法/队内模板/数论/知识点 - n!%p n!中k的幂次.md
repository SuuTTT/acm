# 知识点 - n!%p n!中k的幂次



## 解决问题类型：

1. ###### 计算n!%p

2. ###### 上面的式子可以用来快速算组合数

3. ###### 求最大的k使得$k^x|n!$

   

## 结论、代码与复杂度：

1. ###### 计算n!%p

   **p很大时**，如果n也很大，就用威尔逊定理： $O(p-n)$.
   $$
   (p-1)!+1\equiv 0(mod\ p)
   $$
   然后计算$n*...*(p-1)$的逆元，用它乘-1。

   

   **p较小时**：

    $O(p \log_p n)$.

   
   $$
   \begin{eqnarray}
   n!_{\%p}&=& \underbrace{1 \cdot 2 \cdot 3 \cdot \ldots \cdot (p-2) \cdot (p-1) \cdot 1}\_{1\text{st}} \cdot \underbrace{1 \cdot 2 \cdot 3 \cdot \ldots \cdot (p-2) \cdot (p-1) \cdot 2}\_{2\text{nd}} \cdot \ldots \\\\
   & & \cdot \underbrace{1 \cdot 2 \cdot 3 \cdot \ldots \cdot (p-2) \cdot (p-1) \cdot 1}\_{p\text{th}} \cdot \ldots \cdot \quad \underbrace{1 \cdot 2 \cdot \cdot \ldots \cdot (n \bmod p)}\_{\text{tail}} \pmod{p}.
   \end{eqnarray}
   $$
   

   ```cpp
   int factmod(int n, int p) {
   	int res = 1;
   	while (n > 1) {
   		res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
   		for (int i = 2; i <= n%p; ++i)
   			res = (res * i) % p;
   		n /= p;
   	}
   	return res % p;
   }
   ```

   

2. ######  $n$ 的阶乘中 $p$ 的幂次为

   $O(logn)$
   $$
   \sum_{r=1}^{+\infin}\left[\frac{n}{p^r}\right]
   $$

   ```c++
   int fact_pow (int n, int k) {
   	int res = 0;
   	while (n) {
   		n /= k;
   		res += n;
   	}
   	return res;
   }
   ```

   

## 例题

[n!%p,n是小于p的第一个质数](http://acm.hdu.edu.cn/showproblem.php?pid=6608) ：就用结论1即可

[CodeForces - 1114C ](https://cn.vjudge.net/problem/2208851/origin) : 输出n!在p进制下末尾有几个0





## 代码

```cpp
//如果 是素数，用讲义里的6.1.3定理即可求得答案
//现在 不是素数，那就分解成素数的乘积再求
#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;
ll fac[1005], num[1005], tot, t[1005];
void getfac(ll n) {
	tot = 0; ll temp = n;
	for (ll i = 2; i*i <= temp; i++) {
		if (n%i == 0) {
			fac[++tot] = i;
			num[tot] = 0;
			while (n%i == 0)num[tot]++, n /= i;
		}
	}
	if (n>1)fac[++tot] = n, num[tot] = 1;
}
int main() {
	ll n, b;
	while (cin >> n >> b) {
		getfac(b);
		rep(i, 1, tot)t[i] = 0;
		rep(i, 1, tot) {
			ll now = fac[i];
			while (1) {
				t[i] += n / now;
				if ((long double)now - 1>(long double)n / fac[i])break;
				now *= fac[i];
			}
		}
		ll ans = t[1];
		rep(i, 1, tot)ans = min(ans, t[i] / num[i]);
		cout << ans << endl;
	}
	return 0;
}
```

