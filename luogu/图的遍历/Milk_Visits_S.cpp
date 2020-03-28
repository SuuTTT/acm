#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
/* 
树节点01染色
询问路径上是否有0 or 1
ana1:树链剖分 可做任意颜色
ana2：dfs+主席树 可做任意颜色
ana3：lca 差分  根到某点的1 or 0 数目，然后可求任意两点间1，0数目
ana4：反面考虑输出0的情况：并查集维护连通块，只有当所查询两点是同一连通块且连通块颜色与目标颜色不同时输出0 
 */
int father[maxn],rk[maxn];
int col[maxn];
void init(int n){
    for(int i=0;i<n;i++)father[i]=i;
}
int find(int v){
    return father[v]=father[v]==v?
    v:find(father[v]);
}
void un(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    father[x]=y;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;init(n);
    string s;
    cin>>s;
    int cnt=1;
    for(auto c:s) col[cnt++]=(c=='H');
    rep(i,1,n-1){
        int x,y;cin>>x>>y;
        if(col[x]==col[y])un(x,y);

    }
    rep(i,1,m){
        int x,y;
        char c;
        cin>>x>>y>>c;
        int op=(c=='H');
        if(find(x)==find(y)&&op!=col[x])cout<<0;else cout<<1;
    }
}
/* 
5 5
HHGHG
1 2
2 3
2 4
1 5
1 4 H
1 4 G
1 3 G
1 3 H
5 5 H
 */