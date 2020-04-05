#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define debug(x) cerr<<#x<<": "<<x<<endl
const int inf=0x3f3f3f3f;
typedef long long ll;
const ll mod = (ll)1e9;
int n,m,d;
int pri[10009];
int vis[1009];
int ans[1009];
int f;
int judge(int now){
    int sum=ans[now];
    for(int i=1;i<d&&i<=now;i++){
        sum+=ans[now-i];
        if(pri[sum])return 0;
    }
    return 1;
}
void dfs(int now){
    if(f)return;
    if(now==m-n+1){
        f=1;
        return ;
    }
    for(int i=n;i<=m;i++){
        if(f)return ;
        if(vis[i])continue;
        ans[now]=i;
        if(judge(now)){
            vis[i]=1;
            dfs(now+1);
            vis[i]=0;
        }
    }
}
int main(){
    pri[2]=1;
    for(int i=3;i<=10000;i+=2){
        int flag=1;
        for(int j=3;j*j<=i;j+=2)if(i%j==0)flag=0;
        pri[i]=flag;
    }
    while(~scanf("%d%d%d",&n,&m,&d)){
        if(n==0&&m==0&&d==0)break;
        for(int i=n;i<=m;i++)vis[i]=0;
        f=0;
        dfs(0);
        if(f){
            for(int i=0;i<=m-n;i++){
                printf("%d%c",ans[i],i==m-n?'\n':',');
            }
        }
        else printf("No anti-prime sequence exists.\n");
    }
    return 0;
}