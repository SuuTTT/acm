#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,k,s;
int a[5009];
vector<int>v[5009];
int dp[5009][5009];
int mn[5009][5009];
int main(){
    scanf("%d%d%d",&n,&k,&s);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(k==1){
        int ans=0;
        for(int i=1;i<=n;i++)if(a[i]!=s)ans++;
        printf("%d\n",ans);
        return 0;
    }
    for(int i=1;i<=k;i++){
        int x=i;
        while(x<=n){
            v[i].push_back(a[x]);
            x+=k;
        }
        sort(v[i].begin(),v[i].end());
    }
    for(int i=0;i<=s;i++)dp[1][i]=v[1].size();
    for(int i=0;i<v[1].size();i++)dp[1][v[1][i]]--;
    mn[1][0]=dp[1][0];
    for(int i=1;i<=s;i++)mn[1][i]=min(dp[1][i],mn[1][i-1]);
    for(int i=2;i<=k;i++){
        for(int j=0;j<=s;j++){
            dp[i][j]=mn[i-1][j]+v[i].size();
            for(int g=0;g<v[i].size();g++){
                if(v[i][g]>j)break;
                int x=1;
                while(g+1<v[i].size()&&v[i][g]==v[i][g+1])g++,x++;
                dp[i][j]=min(dp[i][j],(dp[i-1][j-v[i][g]]-x+(int)v[i].size()));
            }
        }
        mn[i][0]=dp[i][0];
        for(int j=1;j<=s;j++)mn[i][j]=min(dp[i][j],mn[i][j-1]);
    }
    printf("%d\n",dp[k][s]);
    return 0;
}
/*

*/