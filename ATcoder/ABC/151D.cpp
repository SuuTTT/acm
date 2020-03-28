#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
/* 
inf 开大（以防想错）
h,w i,j x,y 容易想错
 */
const int maxn=(int)1e6+5;
char mp[21][21];
int dir[4][2]={1,0, 0,-1, -1,0, 0,1};
int d[500][500];
int h,w;
const int inf=500;
int id(int x,int y){return (x-1)*w+y;}

void add(int x,int y){
    rep(i,0,3){
        int dx=x+dir[i][0],dy=y+dir[i][1];
        if(dx<1||dx>h||dy<1||dy>w)continue;
        if(mp[dx][dy]=='.')d[id(x,y)][id(dx,dy)]=d[id(dx,dy)][id(x,y)]=1;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>h>>w;
    int n=h*w;
    rep(i,1,h*w)rep(j,1,h*w)if(i==j)d[i][j]=0;else d[i][j]=inf;
    rep(i,1,h)rep(j,1,w)cin>>mp[i][j];
    rep(i,1,h)rep(j,1,w)if(mp[i][j]=='.')add(i,j);
    rep(k,1,n)rep(i,1,n)rep(j,1,n)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    int ans=0;
    rep(i,1,n)rep(j,1,n)if(d[i][j]!=inf)ans=max(ans,d[i][j]);
    cout<<ans<<endl;
}
/* 
3 5
...#.
.#.#.
.#...
 */