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

ll n,k;
ll dp[maxn];

ll num(ll x){
    if(dp[x])return dp[x];
    ll ret=qpow(k/x,n);
    for(int y=x+x;y<=k;y+=x)ret-=num(y),ret+=MOD,ret%=MOD;
    return dp[x]=ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    ll ans=0;
    for(int x=k;x>=1;x--){
        ans+=x*num(x)%MOD;ans%=MOD;
    }
    cout<<ans<<endl;
}
/* 
ana
有一些性质是没用的 比如1，互质
The necessary and sufficient condition of the greatest common divisor being a multiple of X is that all the A1, ..., AN are multiples of X. 
The number of such sequences is K/X^N .
The necessary and sufficient condition of it being exactly X is that “it is a multiple of X, but not 2X, 3X....”
倒着算即可 即容斥
wa n k 弄混

 */