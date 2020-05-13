#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<(x)<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
const ll mod=(ll)1e9+7;
ll sum(ll l,ll r){
    return (l+r)*(r-l+1)/2%mod;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,k;cin>>n>>k;
    ll ans=0;
    for(ll i=k;i<=n+1;i++){
        ans+=sum(n-i+1,n)-sum(0,i-1)+1;
        ans%=mod;ans+=mod;ans%=mod;
        //debug(sum(n-i+1,n)-sum(0,i-1));
    }
    cout<<ans<<endl;
}