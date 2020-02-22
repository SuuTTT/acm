#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<ll> t;
    ll base=1;
    while(base<=(1ll<<60ll))t.push_back(base),base*=3ll;
    ll n;
    cin>>n;
    ll nn=n/2+1;
    ll tri=1,q=0;

    while(tri<nn)tri*=3ll,q++;
    ll ans=0;
    if(nn==tri){
        ans=q+q;
    }else{
        q--,tri/=3;
        nn=n-2ll*(t[q]-1);
        ans=q+q;
        //debug(q),debug(tri),debug(nn);
        for(int i=q;i>=0;i--){
            ans+=nn/t[i];
            nn=nn%t[i];
        }

    }
    if(n==1)ans=1;
    cout<<ans<<endl;
}