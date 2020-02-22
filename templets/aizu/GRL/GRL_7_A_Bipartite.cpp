#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 6;
int n, m, t, f[N], ans;
vector<int> e[N];
bitset<N> v;

bool dfs(int x) {
    for (unsigned int i = 0; i < e[x].size(); i++) {
        int y = e[x][i];
        if (v[y]) continue;
        v[y] = 1;
        if (!f[y] || dfs(f[y])) {
            f[y] = x;
            return 1;
        }
    }
    return 0;
}

int main() {
    cin >> n >> m >> t;
    while (t--) {
        int x, y;
        scanf("%d %d", &x, &y);x++,y++;
        e[x].push_back(y + n);
        e[y+n].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        v.reset();
        ans += dfs(i);
    }
    cout << ans << endl;
    return 0;
}
/* 
3 4 6
0 0
0 2
0 3
1 1
2 1
2 3

|X| |Y| |E|
x0 y0
x1 y1
:
x|E|−1 y|E|−1

1 ≤ |X|, |Y| ≤ 100
0 ≤ |E| ≤ 10,000
 */