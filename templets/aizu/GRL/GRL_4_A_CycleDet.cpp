#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int n,m;
vector<int> E[maxn];
int vis[maxn];
int flag=1;
int curvis[maxn];
void dfs(int x){
    if(flag==0)return;
    if(vis[x]||curvis[x])return;//不加这个会T，难以想象
    curvis[x]=1;
    vis[x]=1;
    for(auto t:E[x]){
        if(curvis[t]){flag=0;return;}
        dfs(t);
    }
    curvis[x]=0;
}
int main(){
   // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;           
    rep(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        E[x].push_back(y);
    }
    
    rep(i,0,n-1){
        if(flag==0)break;
        if(!vis[i])dfs(i);
    }
    cout<<!(flag)<<endl;
}
/*
10 0

3 3
0 1
0 2
1 2

3 3
0 1
1 2
2 0
 */