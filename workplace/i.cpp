#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)5e2+5;
typedef long long ll;
const long long inf=(ll)1e18;
int gas[maxn];
ll g[maxn][maxn];
int n,m,t,d;
void floid(){
    rep(k,1,n)rep(i,1,n)rep(j,1,n)
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
bool rest(int x){
    return x==1||x==n||gas[x];
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>n>>m>>t>>d;
    rep(i,1,t){
        int x;cin>>x;
        gas[x]=1;
    }
    rep(i,1,n)rep(j,1,n)g[i][j]=inf;
    rep(i,1,m){
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=z;
        g[y][x]=z;
    }
    
    rep(k,1,n)rep(i,1,n)rep(j,1,n)
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    rep(i,1,n)rep(j,1,n){
        if(rest(i)&&rest(j))continue;
        g[i][j]=inf;
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n)
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    cout<<g[1][n]<<endl;

}
/*
6 7 2 4
2 5
1 2 4
1 3 5
2 3 3
3 4 2
3 5 1
4 6 4
5 6 4
*/