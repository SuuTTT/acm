#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<(x)<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
const ll mod=(ll)1e9+7;
ll a[maxn];
bool b[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;

    rep(i,1,n)cin>>a[i];
    int t=60;
    ll b=1;
    ll ans=0;

    while(t--){
        ll zero=0,one=0;
        rep(i,1,n){
            if(a[i]&1)one++;else zero++;
            a[i]>>=1;
        }
        ans+=one*zero%mod*(b%mod)%mod;
        ans%=mod;
        b<<=1;
    }
    cout<<ans<<endl;
}
/* 
每次乘都要用上限估计
对b单独mod
 */