#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int low[maxn];
int vis[maxn],lv[maxn];
vector<int> E[maxn];
set<pair<int,int> > bridge;
map<pair<int,int>,int> V;
/* 
1.if there are parellel lines, can't use fa.

 */
void dfs(int now,int curlv,int fa){
    low[now]=curlv;
    lv[now]=curlv;
    vis[now]=1;
    int son_cnt=0;
    for(auto v:E[now]){
        //1.tree edge to fa, or back edge visited by now's descendant
        if(v==fa)continue;
        //2.back edge to now's ancestor
        if(vis[v]) low[now]=min(low[now],lv[v]);
        //3.tree edge to son.
        else{
            son_cnt++;
            dfs(v,curlv+1,now);
            low[now]=min(low[now],low[v]);
            if(low[v]>lv[now]){
                bridge.insert({min(now,v),max(now,v)});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,1,m){
        int x,y;
        cin>>x>>y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    rep(i,0,n-1)if(!vis[i])dfs(i,0,-1);
   // rep(i,0,n-1)debug(i),debug(low[i]);
    for(auto e:bridge)cout<<e.first<<' '<<e.second<<endl;
}
/* 
4 4
0 1
0 2
1 2
2 3
 */