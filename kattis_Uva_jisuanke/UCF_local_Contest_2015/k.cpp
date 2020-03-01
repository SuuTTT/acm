#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
inline ll qpow(ll a, ll b) {return b? ((b&1)? a*qpow(a*a%MOD,b>>1)%MOD: qpow(a*a%MOD,b>>1))%MOD: 1;}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    ll n,x;
    cin>>x>>n;
    rep(i,1,n){
        debug(kpow(x,i-1)*c(n,i-1)%4);
        
    }
}
/* 
3
3 5
1 4
4 6
 */