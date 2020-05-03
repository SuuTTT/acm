#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)2e3+5;


pair<int,int> a[maxn];
typedef long long ll;
ll dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n){
        int x;cin>>x;
        a[i]={x,i};
    }
    sort(a+1,a+1+n,greater<pair<int,int>>());
    rep(s,1,n)rep(x,0,s){
        
        ll y=s-x;
        ll ai=a[s].first,i=a[s].second;//debug(ai);
        ll c=0;
        if(x>0){
            c=dp[x-1][y]+(n+1-x-i)*ai;
            dp[x][y]=max(c,dp[x][y]);
        }
        if(y>0){
            c=dp[x][y-1]+(i-y)*ai;
            dp[x][y]=max(c,dp[x][y]);
        }
    }
    ll ans=0;
    rep(i,0,n)ans=max(ans,dp[i][n-i]);
    cout<<ans<<endl;
}
/* 
ana:
xjb贪心：从大到小移到两边 wr:没有正确性，因为考虑两边的那个数换到中间后，轮到它时选较大的一边不是最优的（要选和初始移动方向相同的那一边）

考虑终态。记Ai 最终移动到p[i]，ans=sum(Ai|i-p[i]|)

注意到方向，即|i-p[i]|=max(i-p[i],p[i]-i)，将其分为两组。

考虑 i-p[i]， 贪心地按照Ai降序 给pi 赋值1，2，3.因为调换不会更优

实现：dp[x][y]: 考虑前x+y 个，y个选i - pi. 从大到小枚举ai，枚举它放到左右前i个位置的情况
1 3 4 2
4 2 1 3
 */