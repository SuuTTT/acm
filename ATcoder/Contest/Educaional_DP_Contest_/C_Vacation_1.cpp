#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn][4],dp[maxn][4];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n)cin>>a[i][1]>>a[i][2]>>a[i][3];
    rep(i,1,n){
        dp[i][1]=max(dp[i-1][2],dp[i-1][3])+a[i][1];
        dp[i][2]=max(dp[i-1][1],dp[i-1][3])+a[i][2];
        dp[i][3]=max(dp[i-1][1],dp[i-1][2])+a[i][3];
        /* rep(j,1,3)rep(k,1,3)if(j!=k){
            dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][k]);
        } */

    }
    int ans=0;
    rep(i,1,3){ans=max(dp[n][i],ans);}
    cout<<ans<<endl;
}
/* 
不能两天选同样的。
dp[i][123]:结尾是几的最大值。
 */