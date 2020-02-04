#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
typedef long long ll;


#define pli pair<ll,int>
#define  x first
#define  y second
const int maxn=5e5;
int vis[maxn];
ll ans[maxn],t[maxn];
int a[maxn],b[maxn];
ll c[maxn];
priority_queue<pair<ll,int> > Q;
vector<pli> E[maxn] ;
void bfs(){
    while(!Q.empty()){
        while(vis[Q.top().y])Q.pop();
        pli now=Q.top();vis[now.y]=1;
        debug(now.y);
        ans[now.y]=-now.x;
        Q.pop();
        for(auto v:E[now.y]){
            if(vis[v.y])continue;
            Q.push({now.x+v.x,v.y});
        }
    }
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    
    rep(i,1,m){
        scanf("%d%d%lld",&a[i],&b[i],&c[i]);
    }
        
    rep(i,1,n)scanf("%lld",t[i]);

    int tot=n;
    rep(i,1,m){
        ++tot;
        E[a[i]].push_back({-c[i],tot});
        E[tot].push_back({-t[a[i]],a[i]});
        E[b[i]].push_back({-c[i],tot});
        E[tot].push_back({-t[b[i]],b[i]});
    }
    rep(i,1,k){
        ll x;
        scanf("%d",x);
        Q.push({-t[x],x});
    }
    debug(k);
    bfs();
    rep(i,1,n)cout<<ans[i]<<endl;
}
/*
5 5 1
1 2 1
2 3 4
3 4 5
4 5 10
1 5 13
1 2 3 4 5
1
*/