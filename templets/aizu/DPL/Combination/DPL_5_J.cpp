#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
const ll MOD=(ll)1e9+7;
//等价于n拆分成小于等于k个正整数的方案数
ll dp[1005][1005];//dp[i][j] j拆成i个非负数

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    n-=k;
    for(int i=0;i<=k;i++){
        dp[i][0]=1;
        for(int j=1;j<=n;j++){
            if(j-i>=0)
            dp[i][j]+=dp[i][j-i];//每个数加1？

            if(i-1>=0)
            dp[i][j]+=dp[i-1][j];//拆出个0
            
            dp[i][j]%=MOD;
        }
    }
    if(n>=0)cout<<dp[k][n]<<endl;
    else cout<<0<<endl;
}