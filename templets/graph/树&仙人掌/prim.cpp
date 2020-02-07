/* 
time: O(V^2)
g[i][j].fi is id, .se is weight

 */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
bool v[maxn];//是否已经加入生成树
int dis[i];//未标记的节点i加入最小生成树的最小权值。
void prim(){
    memset(v,0,sizeof(v));
    rep(i,1,N)dis[i]=INF;
    dis[1]=0;
    int ans=0;
    rep(i,1,N){
        int mark=-1;
        rep(j,1,N)if(!v[j])
            if(mark==-1)mark=j;
            else if(dis[j]<dis[mark])mark=j;
        if(mark=-1)break;
        v[mark]=1;
        ans+=dis[mark];
        for(int j=0;j<g[mark].size();j++)if(!v[g[mark][j].first]){
            int x=g[mark][j].first;
            dis[x]=min(dis[x],g[mark][j].second);
        }
    }
    return ans;
}
int main(){
ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}