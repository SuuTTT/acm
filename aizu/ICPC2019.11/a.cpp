#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
vector<ll> t;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    ll base=1;t.push_back(base);
    while(base<=(1ll<<55ll))base*=3ll,t.push_back(base);
    ll n;
    cin>>n;
    if(n<=3){
        cout<<n<<endl;
        return 0;
    }
    int q=0;
    while(t[q]*2ll-2<=n)q++;
    q--;
    n-=(t[q]*2ll-2);
    ll ans=q+q;
    //debug(q),debug(n);
    rep(i,0,q){
        ans+=n%3;
        n/=3;
    }
    ans+=n*3;
    cout<<ans<<endl;
}