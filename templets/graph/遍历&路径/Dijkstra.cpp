#include<bits/stdc++.h>
//

// SJTU, O(n^2)
//no negative wheight, source is node 1
const int INF=1000000009;
const int MaxN=1000;
int dis[MaxN],//shortest distance source to i
g[MaxN][MaxN],//distance between i and j
N;
bool v[MaxN];

void dijkstra(){
    for(int i=1;i<=N;i++)dis[i]=INF;
    dis[1]=0;
    memset(v,0,sizeof(v));
    for(int i=1;i<=N;i++){
        int mark=-1,mindis=INF;
        for(int j=1;j<=N;j++)
            if(!v[j]&&dis[j]<mindis){
                mindis=dis[j];
                mark=j;
            }
        v[mark]=1;
        for(int j=1; j<=N;j++) if(!v[j])
            dis[j]=min(dis[j],dis[mark]+g[mark][j]);
    }
}

//qscqesze 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
const int maxn=(int)1e5+5;
vector<pii> E[maxn]; 
void dijkstra_(){
    priority_queue<pii,vector<pii>, greater<pii> > Q;
    Q.push()
    while(!Q.empty()){
        pii now=Q.front();Q.pop();
        if(now.fi!=dis[now.se])continue;//小优化
        for(auto v:E[now.se]){
            if(dis[v.fi]>dis[now.se]+v.se){
                dis[v.fi]=dis[now.se]+v.se;
                Q.push({dis[v.fi],v.fi});
            }
                
        }
    }

}

