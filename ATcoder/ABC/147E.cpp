#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)80+5;
int a[maxn][maxn],b[maxn][maxn],dp[maxn][maxn][maxn*maxn*2];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int h,w;cin>>h>>w;
    rep(i,1,h)rep(j,1,w)cin>>a[i][j];
    rep(i,1,h)rep(j,1,w)cin>>b[i][j];
    dp[1][1][abs(a[1][1]-b[1][1])]=1;
    rep(i,1,h)rep(j,1,w)rep(k,0,80*80*2)if(dp[i][j][k]){
        if(i<h){
            dp[i+1][j][abs(k+a[i+1][j]-b[i+1][j])]=1;
            dp[i+1][j][abs(k-a[i+1][j]+b[i+1][j])]=1;
        }
        if(j<w){
            dp[i][j+1][abs(k+a[i][j+1]-b[i][j+1])]=1;
            dp[i][j+1][abs(k-a[i][j+1]+b[i][j+1])]=1;
        }
        
    }
    rep(k,0,80*80*2)if(dp[h][w][k]){cout<<k<<endl;break;}
}
/* 
网格上，每个格子里有两个数字。从1，1 走到h,w ,每经过一格 选一个到集合a，一个到b，问最后两个集合的差绝对值最小是多少。
最优性不能传递？
注意到所有数字的范围都是80以内，把数值也作为状态
wr 最大值是什么？ 80*80*2 why? 递推的时候可以到达这个大小
bool 表：DP[i][j][k] = Can the unbalancedness of a path to square (i, j) be k?

bitset 加速。
const int d=80*160+100;
const int d2=2*d;
int main(){
    int h,w;cin>>h>>w;
    vector<vector<ll>> g(h,vector<ll>(w));
    rep(i,h){
        rep(j,w){
            ll x;cin>>x;
            g[i][j]=x;
        }
    }
    rep(i,h){
        rep(j,w){
            ll x;cin>>x;
            g[i][j]=abs(x-g[i][j]);
        }
    }
    vector<vector<bitset<d2>>> dp(h,vector<bitset<d2>>(w));
    dp[0][0][d+g[0][0]]=1;
    dp[0][0][d-g[0][0]]=1;
    rep(i,h){
        rep(j,w){
            if(i){
                dp[i][j]|=dp[i-1][j]<<g[i][j];
                dp[i][j]|=dp[i-1][j]>>g[i][j];
            }
            if(j){
                dp[i][j]|=dp[i][j-1]<<g[i][j];
                dp[i][j]|=dp[i][j-1]>>g[i][j];
            }
        }
    }
    int ans=d2;
    rep(i,d2){
        if(dp[h-1][w-1][i]){
            chmin(ans,abs(i-d));
        }
    }
    cout<<ans<<endl;
    return 0;
}
 */