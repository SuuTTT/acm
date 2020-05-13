#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll mod=11092019;
ll cnt[256];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    ll ans=1;
    
    for(auto c:s)cnt[c]++;
    rep(i,'a','z')ans=ans*(cnt[i]+1)%mod;
    cout<<ans<<endl;
}