#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll MOD=(ll)1e9+7;
//i个球分成j组的方案数
ll dp[1005][1005];//dp[i][j]:i个球分成j组的方案数
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    dp[0][0]=1;
    rep(i,1,n)rep(j,1,i){
        dp[i][j]+=dp[i-1][j]*j%MOD;//加入别的组
        dp[i][j]+=dp[i-1][j-1];//自己一组
        dp[i][j]%=MOD;
    }
    cout<<dp[n][k]<<endl;

}
/* 

 */