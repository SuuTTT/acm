#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define per(i,j,k) for(int i = (int)j;i >= (int)k;i --)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define pb push_back
typedef long long ll;
const int maxn=60;
int a[maxn][maxn];
int vis[maxn][maxn];
int dir[8][2]={1,0,-1,0,10,0,-10,0, 0,1, 0, -1, 0,10, 0,-10};
int sx=0,sy=0,ex=4,ey=4;
struct node{
    int x,y;
};
struct father{
    int x,y;
}f[maxn][maxn];//记录路径
node st,ed;
void bfs()
{
    queue<node> q;
    node now;
    
    q.push({st.x,st.y});
    vis[st.x][st.y]=1;
    while(!q.empty())
    {
        node n=q.front();q.pop();
        
        
        node N;
        int dig[5]={0,n.x/10,n.x%10,n.y/10,n.y%10};
        rep(i,1,4){
            rep(j,-1,1)if(j!=0){
                int tmp=dig[i];
                dig[i]+=j;
                if(dig[i]==10)dig[i]=0;
                if(dig[i]==-1)dig[i]=9;
                N.x=dig[1]*10+dig[2],N.y=dig[3]*10+dig[4];
                if(N.x>23||N.y>59||vis[N.x][N.y]){dig[i]=tmp;continue;}
                
                
                q.push(N);
                f[N.x][N.y].x=n.x;//记录前驱节点
                f[N.x][N.y].y=n.y;
                vis[N.x][N.y]=1;
                if(N.x==ed.x&&N.y==ed.y)return;
                dig[i]=tmp;
            }
        }
        
        
    }
}
vector<string> ans;
void dfs(int x,int y)
{
    if(x==st.x&&y==st.y)return;
    else dfs(f[x][y].x,f[x][y].y);
    string tmp;
    int dig[5]={0,x/10,x%10,y/10,y%10};
    rep(i,1,2)tmp+=dig[i]+'0';
    tmp+=':';
    rep(i,3,4)tmp+=dig[i]+'0';
    ans.push_back(tmp);
}
string trans(int x,int y){
    string tmp;
    int dig[5]={0,x/10,x%10,y/10,y%10};
    rep(i,1,2)tmp+=dig[i]+'0';
    tmp+=':';
    rep(i,3,4)tmp+=dig[i]+'0';
    return tmp;
}
int main()
{
    
    scanf("%d:%d",&st.x,&st.y);
    scanf("%d:%d",&ed.x,&ed.y);
    //debug(st.x);
    bfs();
    ans.push_back(trans(st.x,st.y));
    dfs(ed.x,ed.y);
    
    cout<<ans.size()<<endl;
    for(auto s:ans)cout<<s<<endl;
    return 0;
}
/* 
00:00
23:59
 */
