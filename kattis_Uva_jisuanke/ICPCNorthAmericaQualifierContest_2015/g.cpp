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
int n;
int a[20];
int dp[(1<<15)+10];
int vis[(1<<15)+10];
queue<int>qu;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int m=(1<<n);
    for(int i=0;i<m-1;i++)dp[i]=INF;
    dp[m-1]=0;
    qu.push(m-1);
    vis[m-1]=1;
    while(!qu.empty()){
        int now=qu.front();
        qu.pop();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j||(now&(1<<i))==0||(now&(1<<j))==0)continue;
                int nx=now&(m-1-(1<<i)-(1<<j));
                int res=dp[now]+max(a[i],a[j]);
                for(int k=0;k<n;k++){
                    if((nx&(1<<k))==0){
                        res+=a[k];
                        nx|=(1<<k);
                        break;
                    }
                }
                dp[nx]=min(dp[nx],res);
                if(!vis[nx]){
                    vis[nx]=1;
                    qu.push(nx);
                }

            }
        }
    }
    printf("%d\n",dp[1]-a[0]);
}
/*
开船过桥问题，
船坐两个人，船速是较慢的人的速度，
15个人过完的时间？
*/