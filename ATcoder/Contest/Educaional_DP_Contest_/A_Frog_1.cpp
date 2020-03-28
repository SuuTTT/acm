#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int dp[maxn],h[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n)cin>>h[i];
    dp[1]=0;dp[2]=abs(h[1]-h[2]);
    rep(i,3,n){
        dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout<<dp[n]<<endl;
}
/* 
i->i+1 or i+2, with cost |hi-hj|
dp[i]:走到i的花费
dp[i]=min(dp[i-1]+cost1,dp[i-2]+cost2)
 */