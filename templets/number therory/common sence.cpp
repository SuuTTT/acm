typedef long long ll;
const ll MOD=998244353;
inline ll qpow(ll a, ll b) {return b? ((b&1)? a*qpow(a*a%MOD,b>>1)%MOD: qpow(a*a%MOD,b>>1))%MOD: 1;}
inline ll gcd(ll a, ll b) {return b? gcd(b, a%b): a;}
