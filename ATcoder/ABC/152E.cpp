/* 
1e4个a_i, 求最小公倍数乘1/a_i
 */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
const ll MOD=1e9+7;
inline ll qpow(ll a, ll b) {return b? ((b&1)? a*qpow(a*a%MOD,b>>1)%MOD: qpow(a*a%MOD,b>>1))%MOD: 1;}
inline ll gcd(ll a, ll b) {return b? gcd(b, a%b): a;}
//inline ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
int p[maxn];
void trial_division1(long long n) {//The smallest divisor has to be a prime number.
    for (long long d = 2; d * d <= n; d++)if(n % d == 0) {
        int cnt=0;
        while (n % d == 0) {
            //factorization.push_back(d);
            cnt++;
            n /= d;
        }
        p[d]=max(p[d],cnt);
    }
    if (n > 1)
        //factorization.push_back(n);
        p[n]=max(p[n],1);
    
}

int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
    }
    rep(i,1,n){
       trial_division1(a[i]);        
    }
    ll lcm=1;
    rep(i,1,1000000)if(p[i]){
        lcm*=qpow(i,p[i]);
        lcm%=MOD;
    }
    ll ans=0;
    rep(i,1,n)ans+=qpow(a[i],MOD-2);ans%=MOD;
    debug(lcm);
   // rep(i,1,5)debug(p[i]);
    ans=ans*lcm%MOD;
    
    cout<<ans<<endl;
}