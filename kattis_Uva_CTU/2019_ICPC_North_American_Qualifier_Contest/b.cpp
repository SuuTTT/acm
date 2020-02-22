#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
inline ll gcd(ll a, ll b) {return b? gcd(b, a%b): a;}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll x,y;
    cin>>x>>y;
    //x*=2,y*=2;
    ll g=gcd(x,y);
    x/=g,y/=g;
    ll ans=0;
    if(x%2==1&&y%2==1){
        ans=g;
    }
    else ans=0;
    cout<<ans<<endl;
}