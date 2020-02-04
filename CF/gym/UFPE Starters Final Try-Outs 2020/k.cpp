#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=2000005;
typedef long long ll;
vector<ll> dp[maxn];
int main(){
    int n,m;
    cin>>n>>m;
    rep(j,1,m)dp[0].push_back(0),dp[n+1].push_back(0);
    rep(i,1,n){
        dp[i].push_back(0);
        rep(j,1,m){
            int x;
            scanf("%d",&x);
            dp[i].push_back(x);
        }
        dp[i].push_back(0);
    }
    rep(j,2,m){
        rep(i,1,n){
            dp[i][j]+=max(max(dp[i][j-1],dp[i+1][j-1]),dp[i-1][j-1]);
        }
    }
    ll ans=0;
    rep(i,1,n)ans=max(ans,dp[i][m]);
    cout<<ans<<endl;

}