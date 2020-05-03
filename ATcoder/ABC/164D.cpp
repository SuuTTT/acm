#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int sum[maxn];
const int mod=2019;
int cnt[3000];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int len=s.length();
    len--;
    sum[len]=s[len]-'0';
    int bit=1;
    for(int i=len;i>=0;i--){
        sum[i]=(s[i]-'0')*bit%mod;
        sum[i]+=sum[i+1];
        sum[i]%=mod;
        bit*=10;bit%=mod;
    }
    cnt[0]++;
    int ans=0;
    for(int i=len;i>=0;i--){
        //debug(i),debug(sum[i]);
        ans+=cnt[sum[i]];
        cnt[sum[i]]++;
    }
    cout<<ans<<endl;
}
/* 
3*673

%2019?
 */