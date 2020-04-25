#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
//标程 不懂 貌似是把题解的dp简化了一下
int n;
vector<int> adj[100005];

int dfs(int u, int p) {
    int cur = 0;
    for (int v : adj[u]) if (v != p) cur += dfs(v, u);
    return abs(cur - 1);
}

int main() {
    scanf("%d", &n);
    rep (i, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (dfs(1, 0)) {
        puts("Alice");
    } else {
        puts("Bob");
    }
    return 0;
}