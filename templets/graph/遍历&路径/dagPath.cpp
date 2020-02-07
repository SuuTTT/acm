#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e3+5;
//dag cal shortest path from s to t;
// toposort, then dp:
//dist[v]=min{dist[u]+e(u,v)}
int g[maxn][maxn],f[maxn],n;//f[i]: i to t 最短路
int done[maxn];//做过flag
int dag_bath(int x){
    if(done[x])return f[x];
    rep(i,1,n)if(g[i][x])f[x]=max(f[x],solve(i)+g[i][x]);
    done[x]=true;
    return f[x];
}