#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<int> > S(H, vector<int>(W));
    REP(i, H) {
        string s;
        cin >> s;
        REP(j, W) S[i][j] = s[j] - '0';
    }

    vector<vector<int> > acum_row(H, vector<int>(W));

    REP(i, H) {
        if(S[i][0] == '1') acum_row[i][0] = 1; 
        FOR(j, 1, W-1)
            if(S[i][j] == '1') acum_row[i][j] = acum_row[i][j-1] + 1;
            else acum_row[i][j] = acum_row[i][j-1];
    }

    int ans = 2000;
    for(int i=0; i < (1<<(H-1)); i++) {
        bool feasible = true;
        vector<int> group(H);
        int g = 0;
        REP(h, H) {
            group[h] = g;
            if((i >> h) & 1) g++;
        }
        g++;
        vector<int> counts(g);
        int tmp_ans = g - 1;

        REP(w, W) {
            vector<int> counts_in_col(g);
            REP(h, H) counts_in_col[group[h]] += S[h][w];

            bool do_partition = false;
            REP(g_idx, g) {
                if(counts[g_idx] + counts_in_col[g_idx] > K) do_partition = true;
                if(counts_in_col[g_idx] > K) feasible = false;
            }

            if(do_partition) {
                tmp_ans++;
                counts = counts_in_col;
            } else {
                REP(g_idx, g) counts[g_idx] += counts_in_col[g_idx];
            }
        }
        if(feasible && ans > tmp_ans) ans = tmp_ans;
    }

    cout << ans << endl;

    return 0;
}
/* 
代码难度大
好的写法
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int h, w, k, z, ans=1e9, c[15];
string a[15];

bool f(int j) {
	int i, id=0, fl=0;
	for(i=0; i<h; i++) {
		c[id] += a[i][j]=='1';
		if(c[id]>k) fl = 1;
		if(z>>i & 1) id++;
	}
	return fl;
}

int main() {
	int i, j, cnt, re;
	cin >> h >> w >> k;
	for(i=0; i<h; i++) cin >> a[i];
	for(z=0; z<1<<h-1; z++) {
		memset(c, 0, sizeof(c));
		cnt = __builtin_popcount(z);
		re = 0;
		for(j=0; j<w; j++) {
			if(f(j)) {
				cnt++;
				memset(c, 0, sizeof(c));
				re = f(j);
			}
		}
		if(!re) ans = min(ans, cnt);
	}
	cout << ans;
	return 0;
}

 */