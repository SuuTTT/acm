#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
const int inf=(int)1e9+5;
int ans,n,dp[maxn],a[maxn],Ans[maxn];
vector<int> E[maxn];
void dfs(int x,int fa){
    //debug(x);
    for(auto v:E[x])if(v!=fa){
        int p=lower_bound(dp,dp+1+ans,a[v])-dp;
        int tmp=dp[p],tmpans=ans;
        dp[p]=min(dp[p],a[v]);
        ans=max(p,ans);
        Ans[v]=ans;
        dfs(v,x);
        dp[p]=tmp;
        ans=tmpans;
    }
    //debug(x);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n+2)dp[i]=inf;dp[0]=-1;
    rep(i,1,n-1){
        int x,y;cin>>x>>y;E[x].push_back(y);E[y].push_back(x);
    }
    E[0].push_back(1);
    dfs(0,0);
    rep(i,1,n)cout<<Ans[i]<<endl;
}
/* 
dp[i]: LIS第i位的最小值
applying rollback technique to the dynamic programming of solving the longest increasing subsequence problem.

Here the rollback refers to, when processing updates of values of variables and questions one after another, 
withdrawing the changes as it wasbefore the latest changes. 

wr 下标a[v] , ans 没更新
T debug 没删
 */