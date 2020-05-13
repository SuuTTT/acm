#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define per(i,j,k) for(int i = (int)j;i >= (int)k;i --)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define pb push_back

typedef double db;
typedef long long ll;
const int MAXN = (int)2e3 + 7;
const int INF = (int)0x3f3f3f3f;
struct node{
    int to,next;
    ll w;
}e[200009];
int head[100009],cnt,n;
void add(int u,int v,ll w){
    cnt++;
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
ll t[100009],sumt[100009],fa[100009],sz[100009];
ll dp[100009],dpt[100009],ans[100009],anst[100009];
void dfs_init(int rt,int f){
    fa[rt]=f;
    sumt[rt]=t[rt];
    sz[rt]=1;
    for(int i=head[rt];i;i=e[i].next){
        if(e[i].to==f)continue;
        dfs_init(e[i].to,rt);
        sumt[rt]+=sumt[e[i].to];
        sz[rt]+=sz[e[i].to];
    }
}
void dfs_dp(int rt){
    dp[rt]=dpt[rt]=0;
    for(int i=head[rt];i;i=e[i].next){
        if(e[i].to==fa[rt])continue;
        dfs_dp(e[i].to);
        dp[rt]+=dp[e[i].to]+sz[e[i].to]*e[i].w;
        dpt[rt]+=dpt[e[i].to]+sumt[e[i].to]*e[i].w;
    }
}
void dfs_ans(int rt){
    for(int i=head[rt];i;i=e[i].next){
        if(e[i].to==fa[rt])continue;
        int to=e[i].to;
        ans[to]=ans[rt]-sz[to]*e[i].w+(n-sz[to])*e[i].w;
        anst[to]=anst[rt]-sumt[to]*e[i].w+(sumt[1]-sumt[to])*e[i].w;
        dfs_ans(to);
    }
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t[i];
	for(int i=1;i<n;i++){
        int u,v;ll w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
	}
	dfs_init(1,0);
	dfs_dp(1);
	ans[1]=dp[1];anst[1]=dpt[1];
	dfs_ans(1);
	for(int i=1;i<=n;i++){
        cout<<anst[i]+t[i]*ans[i]<<endl;
	}
    return 0;
}
/*
10 5
4 2 5 3 1 2 4 2 1 3
*/
