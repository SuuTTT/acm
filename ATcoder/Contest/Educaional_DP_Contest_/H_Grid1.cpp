#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
char mp[1005][1005];
long long dp[1005][1005];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int h,w;
    cin>>h>>w;
    rep(i,1,h){
        cin>>mp[i]+1;
    }
    dp[1][1]=1;
    rep(i,1,h)rep(j,1,w)if(mp[i][j]=='.'){
        if(mp[i-1][j]=='.')dp[i][j]+=dp[i-1][j];
        if(mp[i][j-1]=='.')dp[i][j]+=dp[i][j-1];
        //debug(i),debug(dp[i][j]);
        dp[i][j]%=(long long)1e9+7;
    }
    cout<<dp[h][w]<<endl;
}