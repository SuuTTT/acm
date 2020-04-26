#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e3+5;
int tim[maxn][maxn];
string mp[maxn];
typedef pair<int,int> pii;
#define x first
#define y second
int dir[4][2]={1,0, 0,-1, -1,0, 0,1};
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    rep(i,0,n-1){
        cin>>mp[i];
    }
    queue<pii> Q;
    Q.push({0,0});
    tim[0][0]=1;
    while(!Q.empty()){
        auto cur=Q.front();
        //cout<<cur.x<<' '<<cur.y<<endl;
       Q.pop();
        if(cur==make_pair(n-1,m-1)){
            cout<<tim[n-1][m-1]-1<<endl;
            return 0;
        }
        rep(i,0,3){
            int t=mp[cur.x][cur.y]-'0';
            int dx=cur.x+t*dir[i][0];
            int dy=cur.y+t*dir[i][1];
            if(dx<0||dx>=n||dy<0||dy>=m||tim[dx][dy])continue;
            Q.push({dx,dy});
            tim[dx][dy]=tim[cur.x][cur.y]+1;
        }
    }
    cout<<-1<<endl;
}
/* 

5 4
2120
1203
3113
1120
1110
 */