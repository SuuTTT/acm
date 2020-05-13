#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
int dp[10][12][2];
vector<int> num;
int f(int pos,int st,int flag){
    
    if(pos==num.size())return abs(num[pos]-st)>=2;
    //if(abs(num[pos]-st)<2)return 0;
    int &DP=dp[pos][st][flag];
    if(DP!=-1)return DP;
    int upper=flag?num[pos]:9;
    DP=0;
    rep(i,0,upper)if(abs(i-st)>=2)
    if(st==11&&i==0)DP+=f(pos+1,11,flag&&i==upper);
    else DP+=f(pos+1,i,flag&&i==upper);
    return DP;
}
int solve(int x){
    num.clear();
    memset(dp,-1,sizeof(dp));
    while(x)num.push_back(x%10),x/=10;
    reverse(num.begin(),num.end());
    return f(0,11,1);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int l,r;cin>>l>>r;
    
   // cout<<solve(r)<<endl;
    cout<<solve(r)-solve(l-1)<<endl;
}