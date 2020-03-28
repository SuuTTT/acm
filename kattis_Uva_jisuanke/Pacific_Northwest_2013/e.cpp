#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
const int N=1005;
char mp[1005][1005];
int dis[N][N],val[256];
int k,w,h,ans;
int dir[4][2]={1,0, 0,-1, -1,0, 0,1 };
struct node{
    int x,y,d;
    node (int xx,int yy,int dd):x(xx),y(yy),d(dd){}
    bool operator< (node const &a)const { return d>a.d; }
};
void bfs(int sx,int sy){
    priority_queue<node> Q;
    rep(i,1,h)rep(j,1,w)dis[i][j]=(int)1e9+5;
    Q.push(node(sx,sy,0));
    dis[sx][sy]=0;
    while(!Q.empty()){
        node now=Q.top();
        Q.pop();
        if(now.x==1||now.x==h||now.y==1||now.y==w){ans=now.d;return;}
        rep(i,0,3){
            int dx=now.x+dir[i][0];
            int dy=now.y+dir[i][1];
            if(dx>=1&&dx<=h&&dy>=1&&dy<=w&&dis[dx][dy]>dis[now.x][now.y]+val[mp[dx][dy]]){
                dis[dx][dy]=dis[now.x][now.y]+val[mp[dx][dy]];
                Q.push(node(dx,dy,dis[dx][dy]));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
  
        cin>>k>>w>>h;
        rep(i,1,k){
            char c;
            int x;cin>>c>>x;
            val[c]=x;
        }
        rep(i,1,h)cin>>mp[i]+1;
        rep(i,1,h)rep(j,1,w){
            if(mp[i][j]=='E')bfs(i,j);
        }
        cout<<ans<<endl;
    }

}
/* 
2
6 3 3
A 1
B 2
C 3
D 4
F 5
G 6
ABC
FEC
DBG
2 6 3
A 100
B 1000
BBBBBB
AAAAEB
BBBBBB
 */