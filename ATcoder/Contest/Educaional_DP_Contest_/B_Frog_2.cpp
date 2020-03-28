#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int dp[maxn],h[maxn];
const int inf=1e9;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    rep(i,1,n)cin>>h[i];
    
    rep(i,1,n)dp[i]=inf;
    dp[1]=0;
    rep(i,1,n){
        rep(j,1,k)if(i-j>0)
        dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
    }
    cout<<dp[n]<<endl;
}
/* 
i->i+1 or i+2 ... or i+k, with cost |hi-hj|
dp[i]:走到i的花费
dp[i]=min(dp[i-1]+cost1,dp[i-2]+cost2)
 */