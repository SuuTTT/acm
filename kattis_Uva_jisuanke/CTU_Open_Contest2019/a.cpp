#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<": "<<x<<endl
typedef long long ll;
const ll mod = (ll)1e9+7;
int a,b,c,k;
ll quick(ll a,ll x){
    if(x==0)return 1;
    if(x==1)return a;
    ll m=quick(a,x/2);
    m=m*m%mod;
    if(x&1)m=m*a%mod;
    return m;
}
ll ni(ll x){
    return quick(x,mod-2);
}
int main()
{
    scanf("%d%d%d%d",&a,&b,&k,&c);
    if(a!=c&&b!=c)printf("0\n");
    else if(a==b)printf("%d\n",k);
    else {
        ll ans=quick(2,k)*k%mod*ni(2)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}