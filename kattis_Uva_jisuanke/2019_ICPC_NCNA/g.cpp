#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
//int dir={1,0, 1,1, }
string mp[105];
int color[105][105],clr;
int ok[10005];
int n,m;
void dfs(int x,int y){
    //debug(x),debug(y),debug(color[x][y]);
    color[x][y]=clr;
    rep(dx,-1,1)rep(dy,-1,1){
        if(dx==0&&dy==0)continue;
        if(color[x+dx][y+dy])continue;
        if(x+dx<0||x+dx>=n||y+dy<0||y+dy>=m)continue;
        if(mp[x+dx][y+dy]=='.')continue;
        dfs(x+dx,y+dy);
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    rep(i,0,n-1)cin>>mp[i];
    rep(i,0,n-1)rep(j,0,m-1)if(mp[i][j]=='#'){
        if(!color[i][j]){
            clr++;
            dfs(i,j);
        }
    }
    rep(i,1,clr)ok[i]=1;
     int ans=0;
    rep(x,0,n-1)rep(y,0,m-1)if(mp[x][y]=='#'){
        int cnt=0;
        rep(dx,-1,1)rep(dy,-1,1){
            if(dx==0&&dy==0)continue;
            if(x+dx<0||x+dx>=n||y+dy<0||y+dy>=m)continue;
            if(color[x][y]==color[x+dx][y+dy]){cnt++;}
        }
        if(cnt!=2){
            ok[color[x][y]]=0;
           /*  debug(x),debug(y),debug(cnt);
            debug(color[x][y]),debug(color[x+1][y]); */
        }
    }
    rep(i,1,clr)if(ok[i])ans++;
    //rep(i,1,clr)debug(i),debug(ok[i]);
    cout<<ans<<endl;
}
/* 
12 12
.##########.
#..........#
#..#...##..#
#.##..#..#.#
#......#.#.#
#....#..#..#
#...#.#....#
#..#...#...#
.#..#.#....#
#....#.....#
#.........#.
.#########..
 */