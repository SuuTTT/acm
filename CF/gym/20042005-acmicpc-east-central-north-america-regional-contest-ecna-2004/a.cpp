#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define debug(x) cerr<<#x<<": "<<x<<endl
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
const int inf=0x3f3f3f3f;
typedef long long ll;
const ll mod = (ll)1e9;
const int maxn=1e7+5;
string s;
ll dp[maxn],num[maxn];
int main(){
    IOS;
    while(cin>>s){
        
        if(s=="0")break;
        int n=s.length();
        rep(i,0,n)dp[i]=0,num[i]=0;
        int i=1;
        dp[0]=dp[1]=1;
        for(auto c:s)num[i++]=c-'0';
        
        for (i=2; i<=n; i++){
                if(num[i]!=0) dp[i] = dp[i-1];
                ll tmp=num[i-1]*10+num[i];
                if(tmp>=10&&tmp<=26) dp[i]+=dp[i-2];
        }
        //debug(dp[n-1]);
        cout<<dp[n]<<endl;
    }   
    return 0;
}
/*
25
25114
1111111111
3333333333
0

*/