#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

ll a,b,c,d;
ll f[10000005];

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>a>>b>>c>>d){
        ll n=max(max(a,b),max(c,d));
        rep(i,1,n)f[i]=(b/i-(a-1)/i)*(d/i-(c-1)/i);
        for(ll z=n;z>=1;z--){
            for(ll i=z+z;i<=n;i+=z){
                f[z]-=f[i];
            }
        }
        cout<<f[1]<<endl;
    }
    return 0;
}
/*

*///