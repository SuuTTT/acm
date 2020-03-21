#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl

typedef long long ll;

ll mod = 1e9+7;  // 1e9+9

ll add(ll x,ll y){return (x+y)%mod;}
ll mul(ll x,ll y){return (x*y)%mod;}
ll mpow(ll x,ll y){
  ll v=1;
  for(;y;x=mul(x,x),y>>=1)
    if(y&1)v=mul(v,x);
  return v;
}

ll divi(ll x,ll y){return mul(x,mpow(y,mod-2));}
ll fact[10000000]={1}, factc=0;
ll Fact(ll x){
  while( factc < x ){
    factc++;
    fact[factc]=mul( fact[factc-1] , factc );
  }
  return fact[x];
}

ll nCr(ll n,ll r){
  return divi( Fact(n) , mul( Fact(n-r) , Fact(r) )   );
}
ll nHr(ll n,ll r){
  return nCr( n+r-1 , n-1 );
}
int main(){
    int n,k;
    cin>>n>>k;
    ll ans=0;
    rep(i,0,min(n-1,k)){
        ans+=nCr(n,i)*nHr(n-i,i)%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}
