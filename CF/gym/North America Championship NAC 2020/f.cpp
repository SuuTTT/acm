#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
typedef pair<int,int> pii;
#define se second
#define fi first
const int maxn=(int)1e6+5;
int mp[55][55];
int g[255][255];
int dis[2505];

vector<pair<int,int> > pos[2505],E[2505];
const int inf=1e9;
int n,k,N;
void dijkstra_(){
    priority_queue<pii,vector<pii>, greater<pii> > Q;
    Q.push({0,0});
    while(!Q.empty()){
        pii now=Q.top();Q.pop();
        //if(now.fi!=dis[now.se])continue;//小优化
        for(auto v:E[now.se]){
            if(dis[v.fi]>dis[now.se]+v.se){
                dis[v.fi]=dis[now.se]+v.se;
                Q.push({dis[v.fi],v.fi});
            }
                
        }
    }

}

int id(pair<int,int> pp){
    int r=pp.first;
    int c=pp.second;
    return r*n-n+c;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>n>>k;
    rep(i,1,n)rep(j,1,n){
        cin>>mp[i][j];
        pos[mp[i][j]].push_back({i,j});
    }
    rep(i,1,n*n)dis[i]=inf;
    rep(i,1,k-1){
        for(auto t:pos[i])for(auto u:pos[i+1]){
            E[id(t)].push_back({id(u),abs(t.first-u.first)+abs(t.second-u.second)});
        }
    }
    for(auto t:pos[1])E[0].push_back({id(t),0});
    dijkstra_();
    int ans=inf;
    for(auto u:pos[k])ans=min(ans,dis[id(u)]);
    //if(k==1){cout<<1<<endl;return 0;}
    cout<<(ans>=inf?-1:ans)<<endl;
}
/* 
F 最少的距离 1->k
50*50=2500
10 5
5 1 3 4 2 4 2 1 2 1
4 5 3 4 1 5 3 1 1 4
4 2 4 1 5 4 5 2 4 1
5 2 1 5 5 3 5 2 3 2
5 5 2 3 2 3 1 5 5 5
3 4 2 4 2 2 4 4 2 3
1 5 1 1 2 5 4 1 5 3
2 2 4 1 2 5 1 4 3 5
5 3 2 1 4 3 5 2 3 1
3 4 2 5 2 5 3 4 4 2
 */