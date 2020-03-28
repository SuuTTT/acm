#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll dp[105][100005];
ll w[maxn],v[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,W;
    cin>>n>>W;
    rep(i,1,n)cin>>w[i]>>v[i];

    rep(i,1,n){
        rep(j,0,w[i])dp[i][j]=dp[i-1][j];
        rep(j,w[i],W)
        dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
    }   
    debug(dp[2][3]);
    debug(dp[1][3]);
    cout<<dp[n][W]<<endl;
}
/* 
拿W 最大的价值
dp[i][w]:拿到第i个，重量小于等于w的最大拿法的价值
dp[i][w]=max(dp[i-1][w],dp[i-1][w-w[i]]+v[i]);
滚动优化：从后往前更新 记得倒着算组合数的技巧吗？
dp[w]:价值小于等于w的最大拿法的价值。  
 */