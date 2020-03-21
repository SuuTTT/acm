 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
 #define debug(x) cerr<<#x<<":"<<x<<endl
 const int maxn=(int)1e6+5;
 typedef long long ll;
 const ll MOD=(ll)1e9+7;
inline ll qpow(ll a, ll b) {return b? ((b&1)? a*qpow(a*a%MOD,b>>1)%MOD: qpow(a*a%MOD,b>>1))%MOD: 1;}
inline ll gcd(ll a, ll b) {return b? gcd(b, a%b): a;}
ll c(ll a,ll b){
    ll ret=1;
    rep(i,1,b){
        ret*=a-i+1;ret%=MOD;
        ret*=qpow(i,MOD-2);ret%=MOD;

    }
    return ret;
}
    
 int main(){
     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     ll n,a,b;
     cin>>n>>a>>b;
     debug(c(n,a));debug(c(n,b));
     cout<<((qpow(2,n)-c(n,a)-c(n,b)-1)%MOD+MOD)%MOD;
 }

 /*
 4 1 3
   */