#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
set<int> st[maxn];
int ind[maxn];
int f[maxn],sz[maxn],ans[maxn];
vector<int> e[maxn];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void un(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    f[x]=y;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     int n,m,k;
     cin>>n>>m>>k;
     rep(i,1,n)f[i]=i;
     rep(i,1,m){
         int x,y;cin>>x>>y;
         st[x].insert(y);
         ind[x]++,ind[y]++;
     }
     rep(i,1,k){
         int x,y;cin>>x>>y;
         //if(st[x].count(y))
         e[x].push_back(y);
         e[y].push_back(x);
     }  
    rep(i,1,n)for(auto t:st[i])un(i,t);
    rep(i,1,n)sz[find(i)]++;
    rep(i,1,n){
        ans[i]=sz[f[i]]-ind[i];
        for(auto t:e[i])if(f[t]==f[i])ans[i]--;
        cout<<ans[i]-1<<' ';
    }
}
/* 
先用friendship （建图，染色）直接并查集。
有blockship就删边、XXX首先blockship是分别有效，其次没有重边， 要分别统计
freindship 直接减去
4 4 1
2 1
1 3
3 2
3 4
4 1
 */