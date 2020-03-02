#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
struct Point{
    int x,y;
}s,t,p[1009];
int dis(Point a,Point b){
    return (int)ceil(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
int b,c[109];
int T,n;
struct edge{
    int to,w;
    edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge>mp[1009];
int dp[1009][109];
int main(){
    scanf("%d%d",&s.x,&s.y);
    scanf("%d%d",&t.x,&t.y);
    scanf("%d",&b);
    scanf("%d",&c[0]);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)scanf("%d",&c[i]);
    scanf("%d",&n);
    p[n]=s;p[n+1]=t;
    for(int i=0;i<n;i++)mp[n].push_back(edge(i,0));
    for(int i=0;i<=n;i++)mp[i].push_back(edge(n+1,0));
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        int l;
        scanf("%d",&l);
        for(int j=0;j<l;j++){
            int to,m;
            scanf("%d%d",&to,&m);
            mp[i].push_back(edge(to,m));
            mp[to].push_back(edge(i,m));
        }
    }
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=b;j++)dp[i][j]=100000000;
    dp[n][0]=0;
    for(int i=0;i<=b;i++){
        for(int j=0;j<=n+1;j++){
            for(int k=0;k<mp[j].size();k++){
                int cost=dis(p[j],p[mp[j][k].to]);
                if(i+cost>b)continue;
                dp[mp[j][k].to][i+cost]=min(dp[mp[j][k].to][i+cost],dp[j][i]+c[mp[j][k].w]*cost);
            }
        }
    }
    int ans=100000000;
    for(int i=0;i<=b;i++)ans=min(ans,dp[n+1][i]);
    if(ans>50000000)ans=-1;
    printf("%d\n",ans);
    return 0;
}
/*

*/