#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll dp[100005];
ll w[maxn],v[maxn];
const ll inf=1e18;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,W;
    cin>>n>>W;
    rep(i,1,n)cin>>w[i]>>v[i];
    
    int V=100*1000;
    rep(i,1,V)dp[i]=1e18;
    rep(i,1,n){
        for(int j=V;j>=v[i];j--)
            dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
    }   
    for(int i=V;i>=0;i--)if(dp[i]<=W){cout<<i<<endl;return 0;}

}
/* 
拿W 最大的价值
dp[i][v]:拿到第i个，价值小于等于v的重量最小拿法的价值
dp[i][w]=max(dp[i-1][w],dp[i-1][w-w[i]]+v[i]);
滚动优化：从后往前更新 记得倒着算组合数的技巧吗？
dp[w]:价值小于等于w的最大拿法的价值。  
 */