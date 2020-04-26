#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define per(i,j,k) for(int i = (int)j;i >= (int)k;i --)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define pb push_back

typedef double db;
typedef long long ll;
const int MAXN = (int)2e3+7;
const int INF = (int)0x3f3f3f3f;
int h,t;
int vis[209][209];
struct node{
    int x,y,t;
    node(int x=0,int y=0,int t=0):x(x),y(y),t(t){}
};
queue<node>qu;
int ans;
int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>h>>t){
        if(h==0&&t==0)break;
        debug(h);
        for(int i=0;i<=200;i++){
            for(int j=0;j<=200;j++)vis[i][j]=0;
        }
        while(!qu.empty())qu.pop();
        vis[h][t]=1;
        ans=-1;
        qu.push(node(h,t,0));
        while(!qu.empty()){
            node now=qu.front();
            qu.pop();
            cout<<now.x<<now.y;
            if(now.x==0&&now.y==0){
                ans=now.t;
                break;
            }
            if(now.y>0&&now.y+1<=200&&vis[now.x][now.y+1]==0){
                vis[now.x][now.y+1]=1;
                qu.push(node(now.x,now.y+1,now.t+1));
            }
            if(now.y>1&&now.x+1<=200&&vis[now.x+1][now.y-2]==0){
                vis[now.x+1][now.y-2]=1;
                qu.push(node(now.x+1,now.y-2,now.t+1));
            }
            if(now.x>1&&vis[now.x-2][now.y]==0){
                vis[now.x-2][now.y]=1;
                qu.push(node(now.x-2,now.y,now.t+1));
            }
        }
        printf("%d\n",ans);
    }
    debug(111);
    return 0;
}

/* 
int main()
{
    while(~scanf("%d%d",&h,&t)){
        if(h==0&&t==0)break;
        for(int i=0;i<=300;i++)
            for(int j=0;j<=300;j++)dp[i][j]=INF;
        for(int i=0;i<=300;i++){
            if(i%2==0)dp[i][0]=i/2;
        }
        for(int i=300;i>=0;i--){
            for(int j=300;j>=0;j--){
                if(j>=1&&j<300)dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
                if(j>=2&&i<300)dp[i][j]=min(dp[i][j],dp[i+1][j-2]+1);
            }
        }
        if(dp[h][t]>(int)1e9)dp[h][t]=-1;
        printf("%d\n",dp[h][t]);
    }
    return 0;
}
 */
