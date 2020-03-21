#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll MOD=(ll)1e9+7;
ll qpow(ll a,ll b){return b?((b&1)?a*qpow(a*a%MOD,b>>1)%MOD:qpow(a*a%MOD,b>>1))%MOD:1;}
ll c(ll n,ll m){
    ll ret=1;
    if(n<m)return 0;
    rep(i,1,m){
        ret*=qpow(i,MOD-2);
        ret%=MOD;
        ret*=n-i+1;
        ret%=MOD;
    }
    return ret;
}
ll p(ll n,ll m){
    ll ret=1;
    if(n<m)return 0;
    rep(i,1,m){
        /* ret*=qpow(i,MOD-2);
        ret%=MOD; */
        ret*=n-i+1;
        ret%=MOD;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    cout<<c(n+k-1,k-1)<<endl;
}