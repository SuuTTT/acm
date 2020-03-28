#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int inf=1e9;
/* 
对状态建图最短路
 */
struct
{
    int to,w,next;
}edge[1000005];
int head[50005],tot;
int type[50005];
int dp[51][50005];
void init(int n,int k)
{
    tot=0;
    for(int i=0;i<=n;i++)head[i]=-1,type[i]=0;
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=n;j++)dp[i][j]=inf;
    }
}
void addedge(int a,int b,int w)
{
    edge[tot].to=b;
    edge[tot].w=w;
    edge[tot].next=head[a];
    head[a]=tot++;
}
char tu[5005][5005];
queue<int>qx,qk;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        init(4*n*m,k);
        for(int i=1;i<=n;i++)scanf("%s",tu[i]+1);
        int s,t;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(tu[i][j]=='D')
                {
                    type[(i-1)*m+j]=1;
                    addedge((i-1)*m+j,(i-1)*m+j+m*n,0);
                    addedge((i-1)*m+j+m*n,(i-1)*m+j+2*m*n,0);
                }
                if(tu[i][j]=='A')s=(i-1)*m+j;
                if(tu[i][j]=='B')t=(i-1)*m+j;
                if(i!=1&&tu[i-1][j]!='#')
                {
                    if(tu[i][j]=='D')
                    {
                        addedge((i-1)*m+j+2*n*m,(i-2)*m+j,-1);
                        addedge((i-1)*m+j+n*m,(i-2)*m+j,0);
                    }
                    else
                    {
                        addedge((i-1)*m+j,(i-2)*m+j,0);
                    }
                }
                if(j!=1&&tu[i][j-1]!='#')
                {
                    if(tu[i][j]=='D')
                    {
                        addedge((i-1)*m+j+2*n*m,(i-1)*m+j-1,-1);
                        addedge((i-1)*m+j+n*m,(i-1)*m+j-1,0);
                    }
                    else
                    {
                        addedge((i-1)*m+j,(i-1)*m+j-1,0);
                    }
                }
                if(i!=n&&tu[i+1][j]!='#')
                {
                    if(tu[i][j]=='D')
                    {
                        addedge((i-1)*m+j+2*n*m,i*m+j,-1);
                        addedge((i-1)*m+j+n*m,i*m+j,0);
                    }
                    else
                    {
                        addedge((i-1)*m+j,i*m+j,0);
                    }
                }
                if(j!=m&&tu[i][j+1]!='#')
                {
                    if(tu[i][j]=='D')
                    {
                        addedge((i-1)*m+j+2*n*m,(i-1)*m+j+1,-1);
                        addedge((i-1)*m+j+n*m,(i-1)*m+j+1,0);
                    }
                    else
                    {
                        addedge((i-1)*m+j,(i-1)*m+j+1,0);
                    }
                }
            }
        }
        dp[0][s]=0;
        qx.push(s);qk.push(0);
        while(!qx.empty())
        {
            int x=qx.front();
            int t=qk.front();
            qx.pop();qk.pop();
            for(int i=head[x];i!=-1;i=edge[i].next)
            {
                int to=edge[i].to,w=edge[i].w;
                if(t+type[to]>k)continue;
                if(dp[t+type[to]+w][to]>dp[t][x]+1)
                {
                    dp[t+type[to]+w][to]=dp[t][x]+1;
                    qx.push(to);qk.push(t+type[to]+w);
                }
            }
        }
        int ans=inf;
        for(int i=0;i<=k;i++)ans=min(ans,dp[i][t]);
        if(ans==inf)printf("HAHAHUHU\n");
        else printf("%d\n",ans);
    }
    return 0;
}