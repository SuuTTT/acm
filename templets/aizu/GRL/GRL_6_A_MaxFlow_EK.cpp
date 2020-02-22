#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 6, M = 2e5 + 6, inf = 1e9;
int n, m, s, t, ans, now[N], pre[N];
int Head[N], Edge[M], Leng[M], Next[M], tot = 1;
bitset<N> v;
/* 
O(nm2) ，实际运用中远远达不到，能够处理 1e3 ~ 1e4 规模的网络。
 */
inline void add(int x, int y, int z) {
    Edge[++tot] = y;
    Leng[tot] = z;
    Next[tot] = Head[x];
    Head[x] = tot;
}

inline bool bfs() {
    v.reset();
    queue<int> q;
    q.push(s);
    v[s] = 1;
    now[s] = inf;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = Head[x]; i; i = Next[i]) {
            int y = Edge[i], z = Leng[i];
            if (v[y] || !z) continue;
            now[y] = min(now[x], z);
            pre[y] = i;
            if (y == t) return 1;
            q.push(y);
            v[y] = 1;
        }
    }
    return 0;
}

inline void upd() {
    ans += now[t];
    int x = t;
    while (x != s) {
        int i = pre[x];
        Leng[i] -= now[t];
        Leng[i^1] += now[t];
        x = Edge[i^1];
    }
}

int main() {
    cin >> n >> m ;
    s=1,t=n;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);x++,y++;
        add(x, y, z);
        add(y, x, 0);
    }
    while (bfs()) upd();
    cout << ans << endl;
    return 0;
}
/* 
4 5
0 1 2
0 2 1
1 2 1
1 3 1
2 3 2


 */