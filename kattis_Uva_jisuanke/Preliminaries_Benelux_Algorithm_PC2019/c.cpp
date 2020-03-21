#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int mp[1005][1005];
int vis[1005][1005];//最少用几了几个桥
struct node{
    int x,y,bridge;
};
int n,m,k;
int dir[4][2]={-1,0, 0,1, 1,0, 0,-1};
bool check(int x){
    //用了<=k
    queue<node> Q;
    rep(i,1,n)rep(j,1,m)vis[i][j]=maxn;
    rep(j,1,m){
       node t={1,j,(mp[1][j]<x?1:0)};
        vis[1][j]=t.bridge;
        Q.push(t);
    }
    while(!Q.empty()){
        node now=Q.front();
        
        //debug(Q.size()),debug(now.x),debug(now.y),debug(now.bridge);cout<<endl;
        Q.pop();
        if(now.bridge>vis[now.x][now.y])continue;
        rep(i,0,3){
            int dx=now.x+dir[i][0];
            int dy=now.y+dir[i][1];
            if(dx<1||dx>n||dy<1||dy>m)continue;
            int db=now.bridge+(mp[dx][dy]<x?1:0);
            if(vis[dx][dy]<=db)continue;
            vis[dx][dy]=db;
            if(dx==n)continue;
            Q.push({dx,dy,db});
        }
    }
    int ans=maxn;
    rep(j,1,m){
        ans=min(ans,vis[n][j]);
    }
   // debug(ans);
    return ans<=k;
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    int mx=0;
    rep(i,1,n)rep(j,1,m){scanf("%d",&mp[i][j]);mx=max(mx,mp[i][j]);}
    int l=0,r=mx;
    while(l<=r){
        
        int mid=(l+r)/2;
       // debug(l),debug(r),debug(mid);
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    
    cout<<r<<endl;
}
/* 
5 3 1
1 1 3
3 3 3
0 0 0
2 2 1
1 2 1

5 3 3
2 1 1
2 1 1
1 1 1
1 1 2
1 1 2

5 5 0
2 1 2 2 2
2 2 2 1 2
1 1 1 1 2
1 1 1 1 2
2 2 2 2 2

 */