#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int n,m;
vector<int> E[maxn],ans;
int vis[maxn];
int ind[maxn];
int dp[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,1,m){
        int x,y;
        cin>>x>>y;
        E[x].push_back(y); 
        ind[y]++;
    }
    queue<int> Q;
    rep(i,1,n)if(!ind[i])Q.push(i);
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        vis[now]=1;
        ans.push_back(now);
        for(auto t:E[now]){
            if(vis[t])continue;
            dp[t]=dp[now]+1;
            ind[t]--;
            if(ind[t]==0)Q.push(t);
        }
    }
    int mx=0;
    rep(i,1,n)mx=max(mx,dp[i]);
    cout<<mx<<endl;;
}
/* 
dp[i]：终点为i的最长路
dp[i]=dp[j]+1  for all j->i
更新顺序：toposort
 */
