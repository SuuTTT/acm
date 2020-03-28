#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
double p[maxn],dp[3004][3004],ans;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n)cin>>p[i];
    dp[0][0]=1;
    rep(i,1,n)rep(j,0,i){
        
        dp[i][j]=dp[i-1][j]*(1-p[i])+(j>0?dp[i-1][j-1]*p[i]:0);
        //debug(i),debug(dp[i][j]);
    }
    rep(j,0,n){
        if(j>n-j)ans+=dp[n][j];
    }
    //cout<<ans<<endl;
    printf("%.20lf",ans);
}
/* 
3
0.30 0.60 0.80
head>tail 的概率
dp[i][#head] dp[i][j]=dp[i-1][j] dp[i-1][j-1]
O(1)计算
最后求和
 */