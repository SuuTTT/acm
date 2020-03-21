#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
const ll MOD=(ll)1e9+7;
ll qpow(ll a,ll b){return b?((b&1)?a*qpow(a*a%MOD,b>>1)%MOD:qpow(a*a%MOD,b>>1))%MOD:1;}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    cout<<qpow(k,n)<<endl;
}