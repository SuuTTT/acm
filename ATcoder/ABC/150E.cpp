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

}
/* 
抽象题。
考虑长度为n的01串S，T， 每一位都有权值c。每次flip一位的花费是c_i*(#S,T之间不一样的位数)，记f(s,t)为s->t的min cost
问所有串对的f(s,t)之和。
ana 对于某对， 贪心即可。
1对多， 计数问题，
sol1 由于对称性，我们直接将c排序，不影响答案。
对于c_i 考虑 c_i*k 被加了几次
nCr(i-1,k-1)*kpow(2,k)*kpow(2,i-(1)-k)*kpow(4,n-i)*c_i*k
 */