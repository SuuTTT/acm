#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
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
    int a,b,x,y;
    cin>>x>>y;
    a=(2*y-x);
    b=(2*x-y);
    if(a%3||b%3||a<0||b<0){cout<<0;return 0;}
    a/=3,b/=3;
    cout<<nCr(a+b,a)<<endl;

}