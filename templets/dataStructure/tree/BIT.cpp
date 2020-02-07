#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
/* 
下标从1开始的
 */
template<typename T, size_t size>
struct BIT {
	T a[size]; int n;
	void init(int _n) { n = _n; memset(a, 0, sizeof(T)*(_n + 1)); }
	void erase(int x) { for (int i = x; i <= n; i += i & -i)a[i] = 0; }
	void update(int x, T y) {
		for (int i = x; i <= n; i += i & -i)a[i] += y;
	}
	T query(int x) { T re = 0;  for (int i = x; i; i -= i & -i)re += a[i]; return re; }
};
BIT<ll, maxn>bit;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    bit.init(10);
    bit.update(0,1);
    bit.update(1,1);
    bit.update(2,1);
    debug(bit.query(1));
    debug(bit.query(2));
}