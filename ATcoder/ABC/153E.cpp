#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn],b[maxn],dp[maxn];//dp[i] 伤害为i时的最小花费;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int h,n;
    cin>>h>>n;
    rep(i,1,n){
        cin>>a[i]>>b[i];
    }
    rep(i,1,2e4)dp[i]=(int)1e9+5;
    dp[0]=0;
    rep(i,1,n){
        for(int hp=a[i];hp<=2e4;hp++){
            
            dp[hp]=min(dp[hp],dp[hp-a[i]]+b[i]);
            //debug(hp),debug(dp[hp]);
        }
    }
    int ans=(int)1e9+5;
    rep(i,h,2e4)ans=min(ans,dp[i]);
    cout<<ans<<endl;
}
/* 
9 3
8 3
4 2
2 1
 */