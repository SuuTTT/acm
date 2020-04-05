#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int cnt[4];
double dp[305][305][305];
int n;
double dfs(int i,int j,int k){
   
    if(i==0&&j==0&&k==0)return 0;
    if(dp[i][j][k]>-0.5)return dp[i][j][k];
     //debug(i),debug(j),debug(k);
    double tmp=1.*n/(i+j+k);
    double ret =0;
    if(i)ret+=tmp*i/n*(dfs(i-1,j,k)+tmp);
    if(j)ret+=tmp*j/n*(dfs(i+1,j-1,k)+tmp);
    if(k)ret+=tmp*k/n*(dfs(i,j+1,k-1)+tmp);
    //debug(i),debug(j),debug(k),debug(ret);
    return dp[i][j][k]=ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>n;
    rep(i,1,n){int x;cin>>x;cnt[x]++;}
    rep(i,0,n)rep(j,0,n)rep(k,0,n)dp[i][j][k]=-1;
    
    printf("%.20lf",dfs(cnt[1],cnt[2],cnt[3]));
    //cout<<dfs(cnt[1],cnt[2],cnt[3])<<endl;
}
/* 
n堆寿司(1<=a<=3)，每次等概率选一堆吃一个。吃完的期望次数？
dp[#1个寿司][#2][#3]:该状态的答案 #0=n-rest;
dp[i][j][k]=i/n*(dp[i-1][j][k]+1)+j/n*(dp[i][j-1][k]+1)+k/n*(dp[i][j][k-1]+1)+(n-i-j-k)/n*(dp[i][j][k]);
"转移不能有环"->整理递归式
有问题：
dp[i][j][k] 
选到1：i/n*(dp[i-1][j][k]+1）
选到2：j/n*(dp[i+1][j-1][k]+1)
选到3：k/n*(dp[i][j+1][k-1]+1)
选到0：(n-i-j-k)/n*(dp[i][j][k])

这个不是普通的移项。
分两步：
1。dp[i][j][k]移到一边，
2.1要改变
移项的操作中 1也要变
3
1 1 1

1
3

 */