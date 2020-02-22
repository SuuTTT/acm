#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
void rd(int& n){cin>>n;}
void print(ll n){cout<<n<<endl;}
namespace Dinic {
    const int N = 1e4 + 7, M = 2e5 + 7;
    const ll inf = 1e18;
    int n, m, S, T, h[N], hi[N], e[M], t[M], tot = 1, d[N];
    ll mxf, f[M];
    inline void add(int x, int y, ll z, int o = 1) {
        e[++tot] = y, f[tot] = z, t[tot] = h[x], h[x] = tot;
        if (o) add(y, x, 0, 0);
    }
    inline bool bfs() {
        for (int i = 1; i <= n; i++) d[i] = 0;
        queue<int> q;
        q.push(S), d[S] = 1;
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int i = h[x]; i; i = t[i]) {
                int y = e[i];
                ll z = f[i];
                if (d[y] || !z) continue;
                q.push(y), d[y] = d[x] + 1;
                if (y == T) return 1;
            }
        }
        return 0;
    }
    ll dinic(int x, ll nwf) {
        if (x == T) return nwf;
        ll rst = nwf;
        for (int &i = hi[x]; i && rst; i = t[i]) {
            int y = e[i];
            ll z = f[i];
            if (d[y] != d[x] + 1 || !z) continue;
            ll k = dinic(y, min(z, rst));
            if (!k) d[y] = 0;
            else f[i] -= k, f[i^1] += k, rst -= k;
        }
        return nwf - rst;
    }
    inline void main() {
        while (bfs()) {
            for (int i = 1; i <= n; i++) hi[i] = h[i];
            ll now;
            while ((now = dinic(S, inf))) mxf += now; 
        }
    }
}

int main() {
    rd(Dinic::n), rd(Dinic::m), Dinic::S=1, Dinic::T=Dinic::n;
    for (int i = 1, x, y, z; i <= Dinic::m; i++)
        rd(x), rd(y), rd(z),x++,y++, Dinic::add(x, y, z);
    Dinic::main();
    print(Dinic::mxf);
    return 0;
}
