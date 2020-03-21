#include<iostream>
#include<iomanip>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#define FOR(i, a, b) for(int i = (a);i < (b);++i)
#define FORR(i, b, a) for (int i = (b) - 1;i >= 0;--i)
#define REP(i, n) for(int i = 0;i < (n);++i)
#define REPR(i, n) for(int i = (n) - 1;i >= 0;--i)
#define ITER(itr, v) for(auto itr = v.begin();itr != v.end();++itr)
#define SORT(v) sort(v.begin(), v.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class BIT {
	int n;
	vector<ll> node;
public:
	BIT(int N) :n(N), node(N + 1) {}
	void add(int i, int x) {
		for (++i;i <= n;i += i & -i) node[i] += x;
	}
	ll sum(int i) {
		ll s = 0;
		for (i = min(i, n);i > 0;i -= i & -i) s += node[i];
		return s;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N;
	ll D, A;

	cin >> N >> D >> A;
	
	vector<pair<ll, ll>> XH(N);

	REP(i, N) {
		cin >> XH[i].first >> XH[i].second;
	}

	SORT(XH);

	vector<ll> X(N), H(N);
	REP(i, N) tie(X[i], H[i]) = XH[i];

	BIT bit(N);
	
	int r = 1;
	ll res = 0;
	for (int l = 0;l < N;++l) {//滑窗写法
		H[l] -= bit.sum(l + 1);//BIT区间加
		if (H[l] <= 0) continue;
		ll num = (H[l] + A - 1) / A;
		res += num;
		if (r <= l) r = l + 1;
		while (r < N && X[r] - X[l] <= 2 * D) ++r;
		bit.add(l, num * A);
		bit.add(r, -num * A);
	}
	cout << res << endl;
	return 0;
}
