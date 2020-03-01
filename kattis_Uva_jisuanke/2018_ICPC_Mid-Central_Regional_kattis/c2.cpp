#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
typedef long long ll;

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

int N,M,C;
int vv[30];
char ss[35][35];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int inf=0x3f3f3f3f;
int main(){
   
    scanf("%d%d%d",&M,&N,&C);
    for(int i=0;i<N;i++)scanf("%s",ss[i]);
    for(int i=0;i<C;i++)scanf("%d",&vv[i]);
    Dinic::n=2*N*M+1;
    Dinic::T=2*N*M+1;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            int id=i*M+j+1;
            if(ss[i][j]=='B')Dinic::S=id;
            if(ss[i][j]=='.'||ss[i][j]=='B')Dinic::add(id,id+N*M,inf),Dinic::add(id+N*M,id,0);
            else Dinic::add(id,id+N*M,vv[ss[i][j]-'a']),Dinic::add(id+N*M,id,0);
            for(int k=0;k<4;k++){
                int dx=i+dir[k][0],dy=j+dir[k][1];
                if(dx<0||dy<0||dx>=N||dy>=M)Dinic::add(id+N*M,Dinic::T,inf),Dinic::add(Dinic::T,id+N*M,0);
                else Dinic::add(id+N*M,dx*M+dy+1,inf),Dinic::add(dx*M+dy+1,id+N*M,0);
            }
        }
    Dinic::main();
    if(Dinic::mxf>100000000)Dinic::mxf=-1;
    printf("%d",Dinic::mxf);
    return 0;
}