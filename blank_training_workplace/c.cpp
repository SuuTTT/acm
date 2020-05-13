#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
vector<int> E[maxn];
int vis[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    rep(i,1,m){
        int x,y;cin>>x>>y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    queue<int> Q;
    Q.push(1);
    vis[1]=1;
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        if(now==n){cout<<vis[now]-2<<endl;return 0;}
        for(auto v:E[now])if(!vis[v])Q.push(v),vis[v]=vis[now]+1;
    }
}
/* 
3 3
1 3
1 2
2 3
 */