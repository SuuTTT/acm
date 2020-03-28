#include<bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=200010;
const int inf=1e9;
int  Laxt[maxn],Next[maxn],To[maxn],Len[maxn];
int dp[maxn][22],tmp[22],sz[maxn],cnt,K;
//K<=20
//dp[i][j]表示选择以i为根的子树，子树里有j个点不选的最小权值和。
//和一般的树DP做背包不一样，这里必须选一个（为了保证路径的连通），所以我们用一个临时数组tmp来更新。
//更新答案的时候，选择的连通块的根也不一定是1号节点。
void add(int u,int v,int w)
{
    Next[++cnt]=Laxt[u]; Laxt[u]=cnt; To[cnt]=v; Len[cnt]=w;
}
void dfs(int u,int f)
{
    rep(i,0,K) dp[u][i]=0;
    //dp[u][0]=0; 
    sz[u]=1;
    for(int i=Laxt[u];i;i=Next[i]){
        int v=To[i]; if(v==f) continue;
        dfs(v,u); sz[u]+=sz[v];//size
        rep(j,0,K) tmp[j]=inf;
        rep(j,0,min(sz[v],K)){//枚举补选的点数k，进行类似背包的转移
            rep2(k,K,j)
            tmp[k]=min(tmp[k],dp[u][k-j]+dp[v][j]+(j==sz[v]?0:Len[i]));
        }
        rep(j,0,K) dp[u][j]=tmp[j];
    }
}
int main()
{
    int T,N,u,v,w; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&K);
        cnt=0; rep(i,1,N) Laxt[i]=0;
        rep(i,1,N-1) {
            scanf("%d%d%d",&u,&v,&w);
            u++; v++;
            add(u,v,w); add(v,u,w);
        }
        dfs(1,0); int ans=dp[1][0];
        //rep(i,1,K)  ans=min(ans,dp[1][K]);
        rep(i,1,N) rep(j,0,K-(N-sz[i])) ans=min(ans,dp[i][j]);
        printf("%d\n",ans*2);
    }
    return 0;
}
/* 
D: 给N个点的树，求从任意点出发遍历N-K个点后返回起点的最短路径
3
2 0
0 1 3000
4 1
0 1 81
1 2 41
2 3 59
9 2
0 1 1000
1 2 1200
0 3 1000
3 4 1200
0 5 1000
5 6 1200
0 7 1800
7 8 600

 */