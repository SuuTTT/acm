#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 20 + 5;
const ll inf = 0x3f3f3f3f3f3f;

/* 
原题意是k个点不去，使得路径和最小

转换一下题意就知道这个题就是给定一棵树，删去k条边，保证其联通，求最小权值和，输出时乘上2即可。

随便取个点当作根节点，用dp[i][j]表示以节点i为根节点的子树中删去j条路径的最大权值，dfs遍历每个节点即可。

注意根节点可能会被删除，所以遍历时加个判断，如果某棵子树的节点数就为N-k就用它的权值和更新答案。
 */
struct Node
{
    int v, u, to;
    ll w;
}p[maxn<<1];
int h[maxn];
int tot;
ll dp[maxn][maxm];
int N, k;
ll sum, ans;

void ini()
{
    tot = 0;
    sum = 0;
    memset(h, -1, sizeof(h));
    memset(dp, 0, sizeof(dp));
}

void add(int v,int u,ll w)
{
    p[tot].v = v;
    p[tot].u = u;
    p[tot].w = w;
    p[tot].to = h[v];
    h[v] = tot++;
}

void dfs(int v,int fa,int& cnt,ll& sw)
{//cnt: size of tree. sw:sum of path in tree
    cnt = 1;
    sw = 0;
    for(int t=h[v];~t;t=p[t].to) {
        int u = p[t].u;
        if(u == fa) continue;
        int cn;
        ll sn;
        dfs(u, v, cn, sn);
        if(cn == N-k)
            ans = min(ans, sn*2);

        if(cn <= k)
            dp[u][cn] = dp[u][cn-1]+p[t].w;
        sw += p[t].w + sn;
        cnt += cn;
        for(int i=k;i>=0;i--) {
            ll maxs = 0;
            for(int j=0;j<=i;j++)
                maxs = max(maxs, dp[v][j]+dp[u][i-j]);
            dp[v][i] = maxs;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        ini();
        scanf("%d%d", &N, &k);
        for(int i=0;i<N-1;i++) {
            int v, u;
            ll w;
            scanf("%d%d%lld", &v, &u, &w);
            add(v, u, w);
            add(u, v, w);
            sum += w;
        }
        int cnt;
        ll sn;
        ans = inf;
        dfs(0, 0, cnt, sn);
        if(cnt==N-k) {
            printf("%lld\n", sum*2);
            continue;
        }
        for(int i=0;i<N;i++)
            ans = min(ans, 2*sum-2*dp[i][k]);
        printf("%lld\n", ans);
    }
    return 0;
}
