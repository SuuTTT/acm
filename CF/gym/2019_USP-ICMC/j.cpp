
#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll a[maxn];
ll isp( ll x){
    if(x==1)return 0;
    int flag=1;
    for(ll i=2;i*i<=x;i++){
            if(x%i==0){flag=0;break;}
    }
    return flag;
}
int n;
ll cal(ll x){
    ll ret=0;
    rep(i,1,n)ret+=(a[i]-x<0?x-a[i]:a[i]-x);
    return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll l=0,r=0;
    if(n%2==1){
       l=r=n/2+1;
    }else{
        l=n/2,r=l+1;
    }
    ll p=0,pl=0,pr=0;
    int flag=0;
    rep(i,a[l],a[r]){
        if(isp(i)){
            p=i;
            flag=1;
            break;
        }
    }
    ll ans=0;
    if(flag){
        ans=cal(p);
        //debug(ans);
    }else{
        l=a[l],r=a[r];
        while(l>=2&&!isp(l))l--;
        if(l==1)l=(ll)1e9+7;
        while(!isp(r))r++;
        ans=min(cal(l),cal(r));
    }
    cout<<ans<<endl;
}
/* 
5
3 5 5 7 11 */