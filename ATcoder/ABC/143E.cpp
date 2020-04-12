#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
const int inf=(int)1e9+5;
int n,m,l;
int E[maxn];
int g[2][305][305];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>l;
    rep(i,0,1)rep(j,1,n)rep(k,1,n)g[i][j][k]=(j==k?0:inf);
    rep(i,1,m){
        int x,y,z;
        cin>>x>>y>>z;
        g[0][x][y]=z;
        g[0][y][x]=z;
    }
    
    rep(k,1,n)rep(i,1,n)rep(j,1,n)g[0][i][j]=min(g[0][i][j],g[0][i][k]+g[0][k][j]);
    rep(i,1,n)rep(j,1,n)if(g[0][i][j]<=l)g[1][i][j]=1;
    rep(k,1,n)rep(i,1,n)rep(j,1,n)g[1][i][j]=min(g[1][i][j],g[1][i][k]+g[1][k][j]);
    int q;cin>>q;while(q--){
        int x,y;
        cin>>x>>y;
        cout<<(g[1][x][y]==inf?-1:(g[1][x][y]-1))<<endl;
    }
}
/* 
询问任意两点间最少加几次油

预处理能一次油到达的地方，建权值为1的边然后floyd

wr
<=&初始化位置&输出逻辑错误
3 2 5
1 2 3
2 3 3
2
3 2
1 3
 */