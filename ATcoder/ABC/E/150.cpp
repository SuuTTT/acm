#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
typedef long long ll;
ll MOD = (ll)1e9+7;
inline ll qpow(ll a, ll b) {return b? ((b&1)? a*qpow(a*a%MOD,b>>1)%MOD: qpow(a*a%MOD,b>>1))%MOD: 1;}
inline ll gcd(ll a, ll b) {return b? gcd(b, a%b): a;}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    vector<ll> c(n);
    rep(i,1,n)cin>>c[i-1];
    sort(c.begin(),c.end(),greater<ll> ());
    ll ans=0;
    rep(i,0,n-1)ans+=c[i]*(i+2)%MOD,ans%=MOD;
    //debug(ans);
    ans*=qpow(4,n-1);
    ans%=MOD;
    cout<<ans<<endl;
}
/* 
组合数学题。无编程难度
2^N 个二进制串，转化的花费是 按照C_i递减乘不同位数
求所有对花费之和
1.By the observations above and symmetry, we assume that C is monotonically non-increasing.
2.Decompose the contributions of sums, and consider how many times Ci are added.
？？？sum(1..n)C(i,n) =2^n-1
 */