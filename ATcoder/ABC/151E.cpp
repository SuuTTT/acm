#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
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
    if(n<r)return 0;
  return divi( Fact(n) , mul( Fact(n-r) , Fact(r) )   );
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    debug(nCr(1,2));
    int n,k;cin>>n>>k;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    ll mx=0,mn=0;;
    rep(i,1,n){
        mx+=a[i]*nCr(i-1,k-1); 
        mn+=a[n-i+1]*nCr(i-1,k-1);
        mx=(mx%mod+mod)%mod;
        mn=(mn%mod+mod)%mod;
        //debug(mx),debug(mn);
    }
    cout<<((mx-mn)%mod+mod)%mod<<endl;
}
/* 

 */