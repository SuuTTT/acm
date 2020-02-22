#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)5e3+5;
typedef long long ll;
int a[maxn];
int dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    dp[0][0]=1;
    int mx=0;
    rep(i,1,n){
        if(a[i]>mx){
            rep(j,1,m){
                dp[i][j]+=dp[i-1][j];
                dp[i][j+1]+=dp[i-1][i-j];
            }
        }
        mx=max(mx,a[i]);

    }
    ll sum=0;
    rep(j,1,m)sum+=dp[n][j];
    cout<<sum<<endl;
}
/* 
6 3
1 3 4 2 6 5
 */