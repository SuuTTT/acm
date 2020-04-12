#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)3e3+5;
int a[maxn],b[maxn],dp[2][maxn][maxn],ans;
pair<int,int> p[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,t;cin>>n>>t;rep(i,1,n)cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    rep(i,1,n)rep(j,1,t){
        a[i]=p[i].first,b[i]=p[i].second;
        dp[0][i][j]=(j>=a[i]?max(dp[0][i-1][j],dp[0][i-1][j-a[i]]+b[i]):dp[0][i-1][j]);
    }
    rep(i,1,n)rep(j,0,t-1){ans=max(ans,b[i]+dp[0][i-1][j]);}
    cout<<ans<<endl;
    /* int n,t;cin>>n>>t;rep(i,1,n)cin>>a[i]>>b[i];
    rep(i,1,n)rep(j,1,t){dp[0][i][j]=(j>=a[i]?max(dp[0][i-1][j],dp[0][i-1][j-a[i]]+b[i]):dp[0][i-1][j]);}
    rep(i,1,n)rep(j,1,t){dp[1][i][j]=(j>=a[n-i+1]?max(dp[1][i-1][j],dp[1][i-1][j-a[n-i+1]]+b[n-i+1]):dp[1][i-1][j]);}
    rep(i,1,n)rep(j,0,t-1){ans=max(ans,b[i]+dp[0][i-1][j]+dp[1][n-i][t-1-j]);}
    cout<<ans<<endl; */
}
/* 
时间背包 
时间和价值
时间获得一定的价值，t秒内能获得最大的价值. 最后一样东西可以超出t. 
all:[1,3000]
ana 做一个6000的背包？
枚举最后一个物品？ 不能保证最优  枚举最后一个，对剩下的做背包，可以保证正确性，N^3
状态里要存限制？
qscqesze饭卡问题 

dp[0][i][j] 前i个物品拿重量为j的最大价值
dp[1][i][j] 后i个物品拿重量为j的最大价值
ans=for i for j max(dp[0][i][j]+dp[1][n-i+1][t-1-j])

sol2: 时间最长的在最后不会更坏.
枚举最后一个，所有比它小的物品选最优。
排好序后 dp[i-1][j] 代表所有比第i个小的 重量小于t-1的最优解
wr
not 代码问题，样例问题
a[n-i+1]:一个地方改了，其它所有都要改。 if，for里的&后来加的也要改。
背包不优化，第二维 要判>=a[i]?

2 60
10 10
100 100

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, t;
  cin >> n >> t;
  vector<vector<int>> dp(t, vector<int>(2,0));
  for(int i=0; i<n; ++i){
    int a, b;
    cin >> a >> b;
    for(int j=t-1; j>=0; --j){
      dp[j][0] = max(dp[j][0], dp[j][1]+b);
      if(j>=a)dp[j][0] = max(dp[j][0], dp[j-a][0]+b);
      if(j>=a)dp[j][1] = max(dp[j][1], dp[j-a][1]+b);
    }
  }
  cout << dp[t-1][0] << endl;
}

 */