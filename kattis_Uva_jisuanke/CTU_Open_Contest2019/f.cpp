#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<": "<<x<<endl
typedef long long ll;
const ll mod = (ll)1e9+7;
ll n,k;
ll a[1000009];
ll sum[1000009];
ll all;
ll ans;
int main()
{
    ans=(ll)1e18+9;
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)a[i]-=i*k;
    sort(a,a+n);
    all=a[0];
    sum[0]=a[0];
    for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i],all+=a[i];
    for(int i=0;i<n;i++){
        ll res=all-sum[i]-a[i]*(n-1-i)+a[i]*(i+1)-sum[i];
        ans=min(res,ans);
//        printf("%lld %lld %lld\n",all,sum[i],a[i]);
//        debug(res);
    }
    printf("%lld\n",ans);
    return 0;
}