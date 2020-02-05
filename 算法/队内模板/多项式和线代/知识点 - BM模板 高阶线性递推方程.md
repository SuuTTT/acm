# 知识点 - BM模板 高阶线性递推方程



## 解决问题类型：

密码学算法 Reeds-Sloane Peterson decoder算法的一种代替算法。（降维打击）

对于k阶线性递推方程，即
$$
a(k+n)=\sum_{i=1}^{i<=k}C(k-i+1)\cdot a(n+k-i)
$$
(其中C为系数。)

如果知道这个数列的前2k项（实际中运用中这个值可能<k/50 大概因为模数不同？），即可算出这个数列的k个系数。可以直接返回第n项。


$init[m] = \sum_{i=0}^{m-1} init[i] * trans[i]$

论文：**IOI2017**中国国家候选队论文集 《关于数列递归式的一些研究 毛啸 》

博客：

[zzd的博客](https://www.cnblogs.com/zhouzhendong/p/Berlekamp-Massey.html)

[zzq的博客](https://www.cnblogs.com/zzqsblog/p/6877339.html)

## 复杂度：

$O(n^2)$ 可以FFT优化成$O(n\log n）$

## 例题

[2018牛客多校第九场 A](https://ac.nowcoder.com/acm/contest/889/A) ：Sum of nth powers of first n Fibonacci numbers.

根据OEIS [A098531](http://oeis.org/A098531) [A098532](http://oeis.org/A098532) [A098533 ](http://oeis.org/A098533) [A128697](http://oeis.org/A128697)  归纳推广得到 斐波那契数列前n项m次幂和是一个m+2阶的线性递推方程。直接BM模板即可。

push 20项即可，原因不明。

## 代码

模质数可手写版

```cpp

#define rep(i,t,n)  for(ll i =(t);i<=(n);++i)

#define debug(x) cerr<<#x<<":"<<x<<endl
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 25;
ll fpow(ll a, ll n) {
	ll ret = 1;
	while (n) {
		if (n & 1)ret = ret*a%mod;
		a = a * a%mod;
		n >>= 1;
	}
	return ret;
}
vector<ll> BM(const vector<ll> &s) {
	vector<ll> C = { 1 }, B = { 1 }, T;
	ll L = 0, m = 1, b = 1;
	rep(n, 0, s.size() - 1) {
		ll d = 0;
		rep(i, 0, L)d = (d + s[n - i] % mod*C[i]) % mod;
		if (d == 0)m++;
		else {
			T = C;
			ll t = mod- fpow(b,mod - 2)*d%mod;
			while (C.size() < B.size() + m)C.push_back(0);
			rep(i, 0, B.size() - 1)C[i + m] = (C[i + m] + t * B[i]) % mod;
			if (2 * L > n)m++;
			else L = n + 1 - L, B = T, b = d, m = 1;
		}
	}
	return C;
}
ll polySolve(const vector<ll> &s, const vector<ll> &C, ll n) {
	if (n < s.size())return s[n];
	static ll g[N], f[N], d[N];
	ll k = (ll)C.size() - 1, w = 1;
	rep(i, 0, k)f[i] = i == 1, d[i] = i == k ? 1 : C[k - i];
	while ((w << 1) <= n)w <<= 1;
	while (w >>= 1) {
		rep(i, 0, k + k - 2)g[i] = 0;
		rep(i, 0, k - 1)if (f[i])rep(j, 0, k - 1)(g[i + j] += f[i] * f[j]) %= mod;
		for (ll i = k + k - 2; i >= k; i--)if (g[i])rep(j, 1, k)(g[i - j] -= g[i] * d[k - j]) %= mod;
		rep(i, 0, k - 1)f[i] = g[i];
		if (w&n)for (ll i = k; i >= 0; i--)f[i] = i == k ? f[i - 1] : (i == 0 ? -f[k] * d[i] : (f[i - 1] - f[k] * d[i])) % mod;
	}
	ll ans = 0;
	rep(i, 0, k - 1)(ans += f[i] * s[i]) %= mod;
	return ans + (ans < 0)*mod;
}
int main() {
	vector<ll> f = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, };
	vector<ll> c = BM(f);
	ll n;
	while (cin >> n) {
		cout << polySolve(f, c, n - 1) << endl;
	}
}
```



任意模数BM模板

```cpp
#include <bits/stdc++.h>
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>//用tree
 
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mn = 105;
const int mod = 1000000000;
 
int n, m;
 
// given first m items init[0..m-1] and coefficents trans[0..m-1] or
// given first 2 *m items init[0..2m-1], it will compute trans[0..m-1]
// for you. trans[0..m] should be given as that
//      init[m] = sum_{i=0}^{m-1} init[i] * trans[i]
struct LinearRecurrence {
    using int64 = long long;
    using vec = std::vector<int64>;
 
    static void extand(vec &a, size_t d, int64 value = 0) {
        if (d <= a.size()) return;
        a.resize(d, value);
    }
 
    static vec BerlekampMassey(const vec &s, int64 mod) {
        std::function<int64(int64)> inverse = [&](int64 a) {
            return a == 1 ? 1 : (int64) (mod - mod / a) * inverse(mod % a) % mod;
        };
        vec A = {1}, B = {1};
        int64 b = s[0];
        for (size_t i = 1, m = 1; i < s.size(); ++i, m++) {
            int64 d = 0;
            for (size_t j = 0; j < A.size(); ++j) {
                d += A[j] * s[i - j] % mod;
            }
            if (!(d %= mod)) continue;
            if (2 * (A.size() - 1) <= i) {
                auto temp = A;
                extand(A, B.size() + m);
                int64 coef = d * inverse(b) % mod;
                for (size_t j = 0; j < B.size(); ++j) {
                    A[j + m] -= coef * B[j] % mod;
                    if (A[j + m] < 0) A[j + m] += mod;
                }
                B = temp, b = d, m = 0;
            } else {
                extand(A, B.size() + m);
                int64 coef = d * inverse(b) % mod;
                for (size_t j = 0; j < B.size(); ++j) {
                    A[j + m] -= coef * B[j] % mod;
                    if (A[j + m] < 0) A[j + m] += mod;
                }
            }
        }
        return A;
    }
 
    static void exgcd(int64 a, int64 b, int64 &g, int64 &x, int64 &y) {
        if (!b) x = 1, y = 0, g = a;
        else {
            exgcd(b, a % b, g, y, x);
            y -= x * (a / b);
        }
    }
 
    static int64 crt(const vec &c, const vec &m) {
        int n = c.size();
        int64 M = 1, ans = 0;
        for (int i = 0; i < n; ++i) M *= m[i];
        for (int i = 0; i < n; ++i) {
            int64 x, y, g, tm = M / m[i];
            exgcd(tm, m[i], g, x, y);
            ans = (ans + tm * x * c[i] % M) % M;
        }
        return (ans + M) % M;
    }
 
    static vec ReedsSloane(const vec &s, int64 mod) {
        auto inverse = [](int64 a, int64 m) {
            int64 d, x, y;
            exgcd(a, m, d, x, y);
            return d == 1 ? (x % m + m) % m : -1;
        };
        auto L = [](const vec &a, const vec &b) {
            int da = (a.size() > 1 || (a.size() == 1 && a[0])) ? a.size() - 1 : -1000;
            int db = (b.size() > 1 || (b.size() == 1 && b[0])) ? b.size() - 1 : -1000;
            return std::max(da, db + 1);
        };
        auto prime_power = [&](const vec &s, int64 mod, int64 p, int64 e) {
            // linear feedback shift register mod p^e, p is prime
            std::vector<vec> a(e), b(e), an(e), bn(e), ao(e), bo(e);
            vec t(e), u(e), r(e), to(e, 1), uo(e), pw(e + 1);;
            pw[0] = 1;
            for (int i = pw[0] = 1; i <= e; ++i) pw[i] = pw[i - 1] * p;
            for (int64 i = 0; i < e; ++i) {
                a[i] = {pw[i]}, an[i] = {pw[i]};
                b[i] = {0}, bn[i] = {s[0] * pw[i] % mod};
                t[i] = s[0] * pw[i] % mod;
                if (t[i] == 0) {
                    t[i] = 1, u[i] = e;
                } else {
                    for (u[i] = 0; t[i] % p == 0; t[i] /= p, ++u[i]);
                }
            }
            for (size_t k = 1; k < s.size(); ++k) {
                for (int g = 0; g < e; ++g) {
                    if (L(an[g], bn[g]) > L(a[g], b[g])) {
                        ao[g] = a[e - 1 - u[g]];
                        bo[g] = b[e - 1 - u[g]];
                        to[g] = t[e - 1 - u[g]];
                        uo[g] = u[e - 1 - u[g]];
                        r[g] = k - 1;
                    }
                }
                a = an, b = bn;
                for (int o = 0; o < e; ++o) {
                    int64 d = 0;
                    for (size_t i = 0; i < a[o].size() && i <= k; ++i) {
                        d = (d + a[o][i] * s[k - i]) % mod;
                    }
                    if (d == 0) {
                        t[o] = 1, u[o] = e;
                    } else {
                        for (u[o] = 0, t[o] = d; t[o] % p == 0; t[o] /= p, ++u[o]);
                        int g = e - 1 - u[o];
                        if (L(a[g], b[g]) == 0) {
                            extand(bn[o], k + 1);
                            bn[o][k] = (bn[o][k] + d) % mod;
                        } else {
                            int64 coef = t[o] * inverse(to[g], mod) % mod * pw[u[o] - uo[g]] % mod;
                            int m = k - r[g];
                            extand(an[o], ao[g].size() + m);
                            extand(bn[o], bo[g].size() + m);
                            for (size_t i = 0; i < ao[g].size(); ++i) {
                                an[o][i + m] -= coef * ao[g][i] % mod;
                                if (an[o][i + m] < 0) an[o][i + m] += mod;
                            }
                            while (an[o].size() && an[o].back() == 0) an[o].pop_back();
                            for (size_t i = 0; i < bo[g].size(); ++i) {
                                bn[o][i + m] -= coef * bo[g][i] % mod;
                                if (bn[o][i + m] < 0) bn[o][i + m] -= mod;
                            }
                            while (bn[o].size() && bn[o].back() == 0) bn[o].pop_back();
                        }
                    }
                }
            }
            return std::make_pair(an[0], bn[0]);
        };
 
        std::vector<std::tuple<int64, int64, int>> fac;
        for (int64 i = 2; i * i <= mod; ++i)
            if (mod % i == 0) {
                int64 cnt = 0, pw = 1;
                while (mod % i == 0) mod /= i, ++cnt, pw *= i;
                fac.emplace_back(pw, i, cnt);
            }
        if (mod > 1) fac.emplace_back(mod, mod, 1);
        std::vector<vec> as;
        size_t n = 0;
        for (auto &&x: fac) {
            int64 mod, p, e;
            vec a, b;
            std::tie(mod, p, e) = x;
            auto ss = s;
            for (auto &&x: ss) x %= mod;
            std::tie(a, b) = prime_power(ss, mod, p, e);
            as.emplace_back(a);
            n = std::max(n, a.size());
        }
        vec a(n), c(as.size()), m(as.size());
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < as.size(); ++j) {
                m[j] = std::get<0>(fac[j]);
                c[j] = i < as[j].size() ? as[j][i] : 0;
            }
            a[i] = crt(c, m);
        }
        return a;
    }
 
    LinearRecurrence(const vec &s, const vec &c, int64 mod) :
            init(s), trans(c), mod(mod), m(s.size()) {}
 
    LinearRecurrence(const vec &s, int64 mod, bool is_prime = true) : mod(mod) {
        vec A;
        if (is_prime) A = BerlekampMassey(s, mod);
        else A = ReedsSloane(s, mod);
        if (A.empty()) A = {0};
        m = A.size() - 1;
        trans.resize(m);
        for (int i = 0; i < m; ++i) {
            trans[i] = (mod - A[i + 1]) % mod;
        }
        std::reverse(trans.begin(), trans.end());
        init = {s.begin(), s.begin() + m};
    }
 
    int64 calc(int64 n) {
        if (mod == 1) return 0;
        if (n < m) return init[n];
        vec v(m), u(m << 1);
        int msk = !!n;
        for (int64 m = n; m > 1; m >>= 1) msk <<= 1;
        v[0] = 1 % mod;
        for (int x = 0; msk; msk >>= 1, x <<= 1) {
            std::fill_n(u.begin(), m * 2, 0);
            x |= !!(n & msk);
            if (x < m) u[x] = 1 % mod;
            else {// can be optimized by fft/ntt
                for (int i = 0; i < m; ++i) {
                    for (int j = 0, t = i + (x & 1); j < m; ++j, ++t) {
                        u[t] = (u[t] + v[i] * v[j]) % mod;
                    }
                }
                for (int i = m * 2 - 1; i >= m; --i) {
                    for (int j = 0, t = i - m; j < m; ++j, ++t) {
                        u[t] = (u[t] + trans[j] * u[i]) % mod;
                    }
                }
            }
            v = {u.begin(), u.begin() + m};
        }
        int64 ret = 0;
        for (int i = 0; i < m; ++i) {
            ret = (ret + v[i] * init[i]) % mod;
        }
        return ret;
    }
 
    vec init, trans;
    int64 mod;
    int m;
};
 
ll f[25005];
 
ll powmod(ll a, ll b, ll P) {
    ll t = 1;
    for (; b; b >>= 1, a = a * a % P)
        if (b & 1) t = t * a % P;
    return t;
}
 
int main() {
#ifdef trote
    //freopen("in.txt", "r", stdin);
    freopen("../1.txt", "r", stdin);
    //freopen("out2.txt", "w", stdout);
    size_t st = clock();
#endif
    scanf("%d%d", &n, &m);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 25000; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    vector<ll> v;
    ll S = 0;
    for (int i = 0; i < 900; i++) {
        S = (S + powmod(f[i], m, mod)) % mod;
        v.pb(S);
    }
    LinearRecurrence solver(v, mod, false);
    printf("%lld\n", solver.calc(n));
 
    return 0;
}
```

#### [洛谷版](https://www.luogu.org/blog/pks-LOVING/solution-p5487)

```cpp
vector <LL> f[MAXN] ;
int fail[MAXN] ; LL delta[MAXN], now ;
inline void BM(int I){
    int i, j ;
    for (i = 1 ; i <= I ; ++ i){
        for (now = base[i], j = 0 ; j < f[M].size() ; ++ j)
            now = (now - base[i - j - 1] * f[M][j] % Mod) % Mod ;
        delta[i] = now ; if (!delta[i]) continue ; fail[M] = i ;
        if (!M) { f[++ M].resize(i), delta[i] = base[i] ;  continue ; }
        int Id = M - 1, v = f[Id].size() - fail[Id] + i ;
        for (j = 0 ; j < M ; ++ j)
            if (i - fail[j] + f[j].size() < v)
                Id = j, v = i - fail[j] + f[j].size() ;
        f[M + 1] = f[M] ; ++ M ; while (f[M].size() < v) f[M].push_back(0) ;
        LL mul = delta[i] * expow(delta[fail[Id]], Mod - 2) % Mod ;
        (f[M][i - fail[Id] - 1] += mul) %= Mod  ;
        for (j = 0 ; j < f[Id].size() ; ++ j)
            (f[M][i - fail[Id] + j] -= mul * f[Id][j]) %= Mod ;
    }
    K = f[M].size() ;
    for (i = 0 ; i < f[M].size() ; ++ i)
        p[i + 1] = (f[M][i] % Mod + Mod) % Mod, cout << p[i + 1] << " " ; puts("") ;
}
。。。。。。
int main(){
    int W ; cin >> W >> N ; rr int Len = 1, l = 0, i ;
    for (i = 1 ; i <= W ; ++ i) scanf("%lld", &base[i]) ; BM(W) ;
    while (Len < (K << 1)) Len <<= 1, ++ l ; F[0] = 1 ; Len <<= 1, ++ l ;
    for (i = 0 ; i < Len ; ++ i) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (l - 1)) ;
    for (i = 1 ; i <= K ; ++ i) G[K - i] = Mod - p[i] ; T[1] = G[K] = 1, reverse(G, G + K + 1), _Inv(G, IG, Len >> 1) ;
    reverse(G, G + K + 1), NTT(G, Len, 1), NTT(IG, Len, 1) ;
    while(N){
        NTT(T, Len, 1) ;
        if (N & 1) {
            NTT(F, Len, 1) ;
            for (i = 0 ; i < Len ; ++ i) F[i] = F[i] * T[i] % Mod ;
            NTT(F, Len, -1) ; _Div(F, Len) ;
        }
        for (i = 0 ; i < Len ; ++ i) (T[i] *= T[i]) %= Mod ; NTT(T, Len, -1) ; _Div(T, Len), N >>= 1 ;
    }
    for (i = 0 ; i < K ; ++ i) (Ans += (F[i] * base[i + 1]) % Mod) %= Mod ; printf("%lld\n", Ans) ; return 0 ;
}
```



### dls 压行版

```cpp
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=998244353;
ll powmod(ll a,ll b)
{
    ll res=1;
    a%=mod;
    assert(b>=0);
    for(;b;b>>=1)
    {
        if(b&1)
            res=res*a%mod;
        a=a*a%mod;
    }
    return res;
}
int _,n;
namespace linear_seq {
    const int N=10010;
    ll res[N],base[N],_c[N],_md[N];
    vector<int> Md;
    void mul(ll *a,ll *b,int k) {
        for(int i = 0 ; i < k + k ; ++i)
        _c[i]=0;
        for(int i = 0 ; i < k ;++i)
         if (a[i])
         for(int j = 0 ;j < k ;++ j)
            _c[i+j]=(_c[i+j]+a[i]*b[j])%mod;
        for (int i=k+k-1;i>=k;i--)
            if (_c[i])
            for(int j = 0 ; j<(int ) Md.size() ; ++ j)
                _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%mod;
        for(int i =0 ; i< k ; ++i)
        a[i]=_c[i];
    }
    int solve(ll n,VI a,VI b) {
        ll ans=0,pnt=0;
        int k=SZ(a);
        assert( SZ(a) == SZ(b) );
        for(int i = 0 ;i < k ; ++ i)
         _md[k-1-i] = -a[i] ; _md[k] = 1 ;
        Md.clear() ;
        for(int i =0 ; i < k ; ++ i)
            if (_md[i]!=0)
                Md.push_back(i);
        for(int i = 0; i< k ;++ i)
         res[i]=base[i]=0;
        res[0]=1;
        while ((1ll<<pnt)<=n)
        pnt++;
        for (int p=pnt;p>=0;p--) {
            mul(res,res,k);
            if ((n>>p)&1) {
                for (int i=k-1;i>=0;i--) res[i+1]=res[i];res[0]=0;
                for(int j = 0 ;j < (int)Md.size() ; ++ j)
                 res[ Md[j] ]=(res[ Md[j] ]-res[k]*_md[Md[j]])%mod;
            }
        }
        rep(i,0,k) ans=(ans+res[i]*b[i])%mod;
        if (ans<0) ans+=mod;
        return ans;
    }
    VI BM(VI s) {
        VI C(1,1),B(1,1);
        int L=0,m=1,b=1;
        for(int n= 0 ;n < (int)s.size(); ++ n ) {
            ll d=0;
//            rep(i,0,L+1)
            for(int i =0 ; i < L +1 ;++ i)
            d=(d+(ll)C[i]*s[n-i])%mod;
            if (d==0) ++m;
            else if (2*L<=n) {
                VI T=C;
                ll c=mod-d*powmod(b,mod-2)%mod;
                while (SZ(C)<SZ(B)+m)
                    C.push_back(0);
//                rep(i,0,SZ(B))
                for(int i =0 ; i < (int)B.size(); ++ i)
                    C[i+m]=(C[i+m]+c*B[i])%mod;
                L=n+1-L; B=T; b=d; m=1;
            } else {
                ll c=mod-d*powmod(b,mod-2)%mod;
                while (SZ(C)<SZ(B)+m)
                    C.push_back(0);
                for(int i = 0 ;i <(int) B.size() ; ++ i)
                    C[i+m]=(C[i+m]+c*B[i])%mod;
                ++m;
            }
        }
        return C;
    }
    ll gao(VI a,ll n) {
        VI c=BM(a);
        c.erase(c.begin());
        for( int i = 0 ; i < (int)c.size( );++i )
            c[i]=(mod-c[i])%mod;
        return (ll)solve(n,c,VI(a.begin(),a.begin()+SZ(c)));
    }
};

int main() {

        long long  ___ ;VI a;
        int N,v;
        a.push_back(4);
        a.push_back(12);
        a.push_back(33);
        a.push_back(88);
        a.push_back(232);
        a.push_back(609);
        a.push_back(1596);
    for (;~scanf("%lld",&___);)
        printf("%lld\n",linear_seq::gao(a,___-1));
    return 0 ;
}

```



### 非BM输出公式版

```cpp
//duanls
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(int i=a;i<n;i++)
namespace linear
{
    ll mo=1000000009;
    vector<ll> v;
    double a[105][105],del;
    int k;
    struct matrix
    {
        int n;
        ll a[50][50];
        matrix operator * (const matrix & b)const
        {
            matrix c;
            c.n=n;
            rep(i,0,n)rep(j,0,n)c.a[i][j]=0;
            rep(i,0,n)rep(j,0,n)rep(k,0,n)
            c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%mo)%mo;
            return c;
        }
    }A;
    bool solve(int n)
    {
        rep(i,1,n+1)
        {
            int t=i;
            rep(j,i+1,n+1)if(fabs(a[j][i])>fabs(a[t][i]))t=j;
            if(fabs(del=a[t][i])<1e-6)return false;
            rep(j,i,n+2)swap(a[i][j],a[t][j]);
            rep(j,i,n+2)a[i][j]/=del;
            rep(t,1,n+1)if(t!=i)
            {
                del=a[t][i];
                rep(j,i,n+2)a[t][j]-=a[i][j]*del;
            }
        }
        return true;
    }
    void build(vector<ll> V)
    {
        v=V;
        int n=(v.size()-1)/2;
        k=n;
        while(1)
        {
            rep(i,0,k+1)
            {
                rep(j,0,k)a[i+1][j+1]=v[n-1+i-j];
                a[i+1][k+1]=1;
                a[i+1][k+2]=v[n+i];
            }
            if(solve(n+1))break;
            n--;k--;
        }
        A.n=k+1;
        rep(i,0,A.n)rep(j,0,A.n)A.a[i][j]=0;
        rep(i,0,A.n)A.a[i][0]=(int)round(a[i+1][A.n+1]);
        rep(i,0,A.n-2)A.a[i][i+1]=1;
        A.a[A.n-1][A.n-1]=1;
    }
    void formula()
    {
        printf("f(n) =");
        rep(i,0,A.n-1)printf(" (%lld)*f(n-%d) +",A.a[i][0],i+1);
        printf(" (%lld)\n",A.a[A.n-1][0]);
    }
    ll cal(ll n)
    {
        if(n<v.size())return v[n];
        n=n-k+1;
        matrix B,T=A;
        B.n=A.n;
        rep(i,0,B.n)rep(j,0,B.n)B.a[i][j]=i==j?1:0;
        while(n)
        {
            if(n&1)B=B*T;
            n>>=1;
            T=T*T;
        }
        ll ans=0;
        rep(i,0,B.n-1)ans=(ans+v[B.n-2-i]*B.a[i][0]%mo)%mo;
        ans=(ans+B.a[B.n-1][0])%mo;
        while(ans<0)ans+=mo;
        return ans;
    }
}

int main()
{
//  vector<ll> V={1 ,4 ,9 ,16,25,36,49};
//  vector<ll> V={1 ,1 ,2 ,3 ,5 ,8 ,13};
//  vector<ll> V={2 ,2 ,3 ,4 ,6 ,9 ,14};

    vector<ll> V;
    V.push_back(0);
    V.push_back(2);
    V.push_back(12);
    V.push_back(50);
    V.push_back(180);
    V.push_back(602);
    V.push_back(1932);
    V.push_back(6050);
    //{0,2,12,50,180,602,1932,6050,18660,57002};
    linear::build(V);
    //linear::formula();
    ll n;
    while(~scanf("%lld",&n))
    {
        printf("%lld\n",linear::cal(n-1));
    }
    return 0;
}

```

