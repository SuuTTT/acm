#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define per(i,j,k) for(int i = (int)j;i >= (int)k;i --)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define pb push_back

typedef double db;
typedef long long ll;
const int MAXN = (int)1e3+7;
const int INF = (int)0x3f3f3f3f;

struct Dinic{
    // 用于表示表示边的结构体（终点、容量、反向边）
    struct edge{
        int to,cap,rev;
        edge(int to = 0,int cap = 0,int rev = 0):to(to),cap(cap),rev(rev){}
    };

    int N,M;
    vector<edge> G[MAXN];
    int level[MAXN]; //顶点到源点的距离标号
    int iter[MAXN];  //当前弧，在其之前的边已经没有用了

    //向图中增加一条从s到t容量为cap的边
    void add_edge(int from,int to,int cap) {
        G[from].pb(edge(to,cap,G[to].size()));
        G[to  ].pb(edge(from,0,G[from].size()-1));
    }

    //通过BFS计算从源点出发的距离标号
    void bfs(int s){
        memset(level,-1,sizeof(int)*(N+1));
        queue<int> qu;
        level[s] = 0;
        qu.push(s);
        while (!qu.empty()) {
            int v = qu.front(); qu.pop();
            rep(i,0,G[v].size()-1) {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    qu.push(e.to);
                }
            }
        }
    }

    //通过DFS寻找增广路
    int dfs(int v,int t,int f) {
        if (v == t) return f;
        for (int &i = iter[v];i < G[v].size();i ++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to,t,min(f,e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    //求解从s到t的最大流
    int max_flow(int s,int t){
        int flow = 0;
        for (;;) {
            bfs(s);
            if (level[t] < 0) return flow;
            memset(iter,0,sizeof(int)*(N+1));
            int f;
            while ((f = dfs(s,t,INF)) > 0)
                flow += f;
        }
    }

    void init(int n){
        N = n;
        rep(i,1,N) G[i].clear();
    }
}d;

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    while (cin >> d.M >> d.N){
        d.init();
        rep(i,1,d.M) {
            int x,y,w;
            cin >> x >> y >> w;
            d.add_edge(x,y,w);
        }
        cout << d.max_flow(1,d.N) << endl;
    }
}