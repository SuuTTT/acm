#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string mp[4];
string color="RGBYW";
typedef pair<int,int> pii;
#define  X first
#define  Y second
vector<pii> pos;

void print(){
    rep(i,0,3)cout<<mp[i]<<endl;
    cout<<endl;
}
int clrnum=0;
int flag=0;
int blocknum;
int vis[4][4];
int dir[4][2]={1,0, 0,-1, -1,0, 0,1 };
void flood(int x,int y){
    vis[x][y]=blocknum;
    rep(i,0,3){
        int dx=x+dir[i][0];
        int dy=y+dir[i][1];
        if(dx>=0 and dx<4 and dy >=0 and dy <4 and vis[dx][dy]==0 and mp[x][y]==mp[dx][dy])flood(dx,dy);
    }
}
bool check(){
    blocknum=0;
    rep(i,0,3)rep(j,0,3)vis[i][j]=0;
    rep(i,0,3)rep(j,0,3){
        if(vis[i][j]==0)blocknum++,flood(i,j);
    }
    if(blocknum==clrnum)return 1;
    return 0;
}
void dfs(int p){
    if(p==pos.size()){
       // print();
        if(check())flag=1;
        return;
    }
    rep(i,0,clrnum-1){
        mp[pos[p].X][pos[p].Y]=color[i];
        dfs(p+1);
        mp[pos[p].X][pos[p].Y]='W';
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rep(i,0,3)cin>>mp[i];
    clrnum=4;
    rep(i,0,3)rep(j,0,3){
        if(mp[i][j]=='W')pos.push_back({i,j});
        if(mp[i][j]=='Y')clrnum=4;
    }
    dfs(0);
    cout<<(flag?"solvable":"not solvable")<<endl;
}
/* 
F 4*4连连看,给定3 or 4对不同颜色的端点，连线过边相邻的格子且在网格内，不能相交,问是否有解。 我暴力试试
RGBW
WWWW
RGBY
YWWW

RGBW
RGBW
RGBY
YYYY


RGBW
WWWW
RGBW
YWWY

RGBX
WWXX
RGBX
YXXY
 */