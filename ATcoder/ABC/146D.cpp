#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define id second
#define vtx first
const int maxn=(int)1e6+5;
typedef  pair<int,int> pii;
int colmx;
vector<pii> E[maxn];
int color[maxn];
void dfs(int cur,int fa,int cf){//color of fa
    int col=0;
    for(auto p:E[cur]){
        if(p.vtx==fa)continue;
        col++;
        if(col==cf)col++;
        colmx=max(colmx,col);
        color[p.id]=col;
        dfs(p.vtx,cur,col);
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n-1){
        int x,y;
        cin>>x>>y;
        E[x].push_back({y,i});
        E[y].push_back({x,i});
    }
    dfs(1,0,0);
    cout<<colmx<<endl;
    rep(i,1,n-1)cout<<color[i]<<endl;
}
/* 
一棵1e5树
给出一个染色方案使得连向某点的边颜色都不同。
其实没wa:wa:dfs,只要记录每个点和父边的颜色，dfs时跳过。所有子边递增即可。
不用：记录所有遍历过的点的颜色->bfs可以
然后记录答案。

3
1 2
2 3
trick
 main()中声明 vector<vector<int>> G(N);
 初始化 vector<int> used(N,0);
 */