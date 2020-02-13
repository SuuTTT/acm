#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
const int inf=(int)1e9+5;
int dp[maxn],a[maxn],n;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>a[i];

    int ans=0;
    int len=0;
    fill(dp+1,dp+1+n,inf);
    rep(i,1,n){
        *lower_bound(dp+1,dp+1+n,a[i])=a[i];
    }
    while(dp[ans]!=inf)ans++;
    cout<<ans-1<<endl;
   /*  rep(i,2,n){
        rep(j,1,i-1){
            if(a[i]>a[j]){dp[i]=max(dp[i],dp[j]+1);
            ans=max(ans,dp[i]);}
        }
    }
    cout<<ans+1<<endl; */
}