#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
const int inf=256;
/* 树形dp 入门1st */
int dp[maxn][2],f[maxn],r[maxn];//dp[i][根节点参加?]:i为根的根节点的最大快乐值。
//r有负数，其实不用考虑
//父亲参加，儿子一定不能参加
vector<int> son[maxn];
void dfs(int v){
    dp[v][1]=r[v];
    //if(son[v].empty())dp[v][0]=0,dp[v][1]=r[v];
    for(auto t:son[v]){
        dfs(t);
        dp[v][0]+=max(dp[t][0],dp[t][1]);
        
        dp[v][1]+=dp[t][0];
    }
    
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n)cin>>r[i];
    rep(i,1,n-1){int x,y;cin>>x>>y;f[x]=y;son[y].push_back(x);}
   // rep(i,1,n)dp[i][1]=dp[i][0]=-inf;
    rep(i,1,n)if(!f[i]){dfs(i);cout<<max(dp[i][0],dp[i][1])<<endl;}
    
}
/* 
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5

 */