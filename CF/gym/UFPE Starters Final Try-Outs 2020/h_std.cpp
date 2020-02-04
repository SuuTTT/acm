#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
typedef long long ll;
const int maxn=(int)2e5+5;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
vector<pii> ve[maxn];
int T[maxn];
ll dis[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        ve[u].push_back({v,w});
        ve[v].push_back({u,w});
    }
    rep(i,1,n)cin>>T[i],dis[i]=(ll)1e18;
    priority_queue< pll,vector<pll>, greater<pll> >q;
    rep(i,1,k){
        int x;
        cin>>x;
        q.push({0,x});
        dis[x]=0;
    }
    while(!q.empty()){
        pll now=q.top();q.pop();
        //if(now.fi!=dis[now.se])continue; //小优化，当前的点不是最短
        for(auto v:ve[now.se]){
            if(dis[v.fi]>dis[now.se]+v.se+T[now.se]){
                dis[v.fi]=dis[now.se]+v.se+T[now.se];
                q.push({dis[v.fi],v.fi});
            }
        }
    }
    rep(i,1,n)cout<<dis[i]+T[i]<<endl;
}