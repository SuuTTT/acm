#include<iostream>
#include<stack>
using namespace std;
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
/*
ll ncr[5000][5000];

ll nCr(ll n,ll r){
  if(n==r)return 1;
  if(r==0)return 1;
  if(ncr[n][r])return ncr[n][r];
  ncr[n][r]=(nCr(n-1,r-1)+nCr(n-1,r))%mod;
  return ncr[n][r];
}
*/

/*
ll nCr(ll n,ll r){
  r=min(r,n-r);
  ll A=1,B=1;
  for(ll i=0;i<r;i++){
    A=mul(A, (n-i)%mod );
    B=mul(B, (i+1)%mod );
  }
  return divi(A,B);
}
*/


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


/*
ll nHr(ll n,ll r){
  return nCr( n+r-1 , n-1 );
}
*/

ll dp[1001][1001];
int main(){
  ll n,k;
  cin>>n>>k;
  dp[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      dp[i][j]+=dp[i-1][j-1];
      dp[i][j]+=dp[i-1][j]*j;
      dp[i][j]%=mod;
    }
  }
  ll ans=0;
  for(int j=1;j<=k;j++)
    ans=add(ans,dp[n][j]);
  cout<<ans<<endl;
  return 0;
}

