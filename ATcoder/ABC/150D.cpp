    #include <bits/stdc++.h>
    using namespace std;
    #define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
    #define debug(x) cerr<<#x<<":"<<x<<endl
    const int maxn=(int)1e6+5;
    /* 
    特判 
     */
    typedef long long ll;
    const ll MOD=1e9+7;
    inline ll qpow(ll a, ll b) {return b? ((b&1)? a*qpow(a*a%MOD,b>>1)%MOD: qpow(a*a%MOD,b>>1))%MOD: 1;}
    inline ll gcd(ll a, ll b) {return b? gcd(b, a%b): a;}
    inline ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
    ll a[maxn];
    int main(){
        ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        ll n,m;
        cin>>n>>m;
        rep(i,1,n){
            cin>>a[i];
            a[i]/=2;
        }
        ll l1=1,l2=1,flag=1;
        rep(i,1,n){
            l1=lcm(l1,a[i]);
            l2=lcm(l2,a[i]*2);
            
            if(l1>m){flag=0;break;}
        }
        rep(i,1,n)if(l1/a[i]%2==0){ printf("0\n"); return 0;}//****
        cout<<(flag?(m/l1-m/l2):0)<<endl;
    }
    /* 
    2 50
    6 10
    */