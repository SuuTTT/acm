#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

int n;
li l, r;

inline bool read() {
	if(!(cin >> n >> l >> r))
		return false;
	return true;
}

bool intersect(li l1, li r1, li l2, li r2) {
	return min(r1, r2) > max(l1, l2);
}

vector<int> ans;

void calc(int lf, int rg, li &id) {
	if(lf == rg) return;
	
	if(intersect(l, r, id, id + 2 * (rg - lf))) {
		fore(to, lf + 1, rg + 1) {
			if(l <= id && id < r)
				ans.push_back(lf);
			id++;
			
			if(l <= id && id < r)
				ans.push_back(to);
			id++;
		}
	} else
		id += 2 * (rg - lf);
	
	calc(lf + 1, rg, id);
	
	if(lf == 0) {
		if(l <= id && id < r)
			ans.push_back(lf);
		id++;
	}
}

inline void solve() {
	ans.clear();
	li id = 0;
	l--;
	calc(0, n - 1, id);
	
	assert(sz(ans) == r - l);
	assert(id == n * li(n - 1) + 1);
	
	for(int v : ans)
		cout << v + 1 << " ";
	cout << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	
	while(tc--) {
		read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}