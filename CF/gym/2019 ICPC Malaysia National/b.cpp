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
    int t;
    cin>>t;
    while(t--){
        cin>>x>>y;
        cout<<(x==y?"YES":"NO")<<endl;
    }
    
   
}
/* 
3 R
>v>
...
<^< */