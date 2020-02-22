#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
map<string,int> val;
struct state
{
    /* data */
    int dir;
    int x,y,t;
    int id(){return (x-1)*51+y-1+dir*51*51;}
   // operator =(const state& r)const{ dir=r.dir;x=r.x,y=r.y,t=t.r; }
};
int n,m;
int mp[55][55];
int vis[10005];
int sx,sy,ex,ey;
//ESWN 0123
string s;
int vec[4][2]={0,1, 1,0, 0,-1, -1,0};
void read(){
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m){
        int x;cin>>x;
        if(x)mp[i][j]=mp[i][j-1]=mp[i-1][j]=mp[i-1][j-1]=1;
        //if(i==n||j==m)mp[i][j]=1;
    }
 /*    rep(i,0,n){
        rep(j,0,m)cout<<mp[i][j]<<' ';
        cout<<endl;
    } */
    cin>>sx>>sy>>ex>>ey>>s;
    //sx++,sy++,ex++,ey++;
    val["E"]=0;
    val["S"]=1;
    val["W"]=2;
    val["N"]=3;
}
int bfs(){
    queue<state> Q;
    Q.push({val[s],sx,sy,0});
    vis[Q.front().id()]=1;
    int cnt=0;
    while(!Q.empty()){
        cnt++;
        state now=Q.front();
        debug(cnt);debug(now.id()),debug(now.x),debug(now.y);debug(now.dir),debug(now.t);
        Q.pop();
        if(now.x==ex&&now.y==ey){
            return now.t;
        }

        state tmp=now;
        rep(i,-1,1)if(i!=0){
            tmp=now;
            tmp.t++;
            tmp.dir=now.dir+i+4,tmp.dir%=4;
            if(vis[tmp.id()])continue;
            Q.push(tmp);vis[tmp.id()]=1;
        }
      
        rep(i,1,3){
            //debug(cnt);debug(now.id()),debug(now.x),debug(now.y);debug(now.dir);
            tmp=now;
            //debug(cnt);debug(tmp.id()),debug(tmp.x),debug(tmp.y);debug(tmp.dir);
            tmp.t++;
            int flag=0;
            rep(ii,tmp.x,tmp.x+vec[tmp.dir][0]*i)rep(jj,tmp.y,tmp.y+vec[tmp.dir][1]*i){
                //debug(cnt);debug(tmp.x),debug(tmp.y);debug(tmp.dir),debug(ii),debug(jj),debug(mp[ii][jj]);
                if(mp[ii][jj]==1)flag=1;
            }
            
            tmp.x+=vec[tmp.dir][0]*i;
            tmp.y+=vec[tmp.dir][1]*i;
            
            if(flag||vis[tmp.id()]||tmp.x>n-1||tmp.x<1||tmp.y>m-1||tmp.y<1
            ||mp[tmp.x][tmp.y]==1)continue;
            Q.push(tmp);
            vis[tmp.id()]=1;
        }
        
    }
    return -1;
}
int main(){

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    read();
   /*  state now={val[s],sx,sy,0};
    state tmp=now;
    debug(tmp.id()),debug(tmp.x),debug(tmp.y);debug(tmp.dir); */
    cout<<bfs()<<endl;
}
/* 
9 10
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
7 2 2 7 S

5 5
0 0 0 0 0 
0 0 1 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
1 1 1 4 E
 */