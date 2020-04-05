#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

ll solve(ll x){
    vector<ll> fac,num;
    ll y=x;
    for(ll i=2;i*i<=x;i++){
        if(y%i==0){
            fac.push_back(i);
            ll t=0;
            while(y%i==0)y/=i,t++;
            num.push_back(t);
        }
    }
    if(y!=1)fac.push_back(y),num.push_back(1);
    ll ans=1;
    rep(i,0,(ll)fac.size()-1){
        ans+=(fac[i]-1)*num[i];
    }
    return ans;
}

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
/*

*///