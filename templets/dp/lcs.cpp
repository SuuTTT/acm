#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e3+5;
int dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    s1='!'+s1;
    s2='@'+s2;
    dp[0][0]=dp[1][0]=dp[0][1]=0;
    rep(i,1,n)rep(j,1,m){
        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+(s1[i]==s2[j]));
        dp[i][j]=max(dp[i][j],dp[i-1][j]);
        dp[i][j]=max(dp[i][j],dp[i][j-1]);
    }
    string ans;
    //rep(i,1,n)rep(j,1,m)debug(dp[i][j]);
    while(n>=0&&m>=0&&dp[n][m]){
        //debug(n),debug(m),debug(dp[n][m]);
        if(dp[n][m]==dp[n-1][m])n--;
        else if(dp[n][m-1]==dp[n][m])m--;
             else ans+=s1[n],n--,m--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
/* 
abcicba
abdkscab
 */