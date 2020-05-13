#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
long long dp[105][105][105];
int L;int k;string n;
long long f(int l,int st,int flag){
    if(st>k)return 0;
    if(l>=L)return st==k;
    if(dp[l][st][flag]!=-1)return dp[l][st][flag];
    int upper=flag?n[l]-'0':9;
    long long ans=0;
    rep(i,0,upper)ans+=f(l+1,st+(i!=0),flag&&(i==upper));
    return dp[l][st][flag]=ans;
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>k;
    L=n.length();
    memset(dp,-1,sizeof(dp));
    //rep(l,0,L)rep(st,0,k)rep(f,0,1)dp[l][st][f]=-1;
    cout<<f(0,0,1);
    cout<<f(0,0,0);
}
/* 
Find the number of integers between 1and N(inclusive) that contains exactly Knon-zero digits when written in base ten.
N<1e100 ,k<4
k==1: 1~9,10~90,100~900...
k==2: 11~99,101 110 
wr :数组越界。。。
 */