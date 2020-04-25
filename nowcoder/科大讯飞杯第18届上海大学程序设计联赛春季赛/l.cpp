
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define per(i,j,k) for(int i = (int)j;i >= (int)k;i --)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define pb push_back

typedef double db;
typedef long long ll;

const int MAXN = (int)2e3+7;
const int INF = (int)0x3f3f3f3f;
const int maxn=1e5+5;
typedef long long ll;
void rd(int& n){cin>>n;}
void print(ll n){cout<<n<<endl;}
namespace Dinic {
    const int N = 1e4 + 7, M = 2e5 + 7;
    const ll inf = 1e18;
    int n, m, S, T, h[N], hi[N], e[M], t[M], tot = 1, d[N];
    ll mxf, f[M];
    inline void init(){
        fill(h,h+1+n,0);
        tot=1;
        mxf=0;
    }
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
int sum;
int c[maxn],a[maxn][8];
int cnt;int n,e;
bool check(int x){
    if(e*x<sum)return 0;
    Dinic::init();
    cnt=0;
    Dinic::S=++cnt,Dinic::T=++cnt;
    rep(i,1,7)Dinic::add(1,++cnt,(x/7+(x%7>=i))*e);
    rep(i,1,n){
        cnt++;
        Dinic::add(cnt,2,c[i]);
        rep(j,1,7)if(a[i][j])Dinic::add(j+2,cnt,INF);
    }
    Dinic::main();
    //d.printG();
    //debug(x);
   // debug(Dinic::mxf);
    //debug(sum);
    //getchar();
    return Dinic::mxf==sum; 
    
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>e;
    rep(i,1,n){
        cin>>c[i];sum+=c[i];
        int m;cin>>m;
        rep(j,1,m){int x;cin>>x;a[i][x]=1;}
    }
    Dinic::n=n+10;
    int l=0,r=1e9,res=0;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
    
}

/* 
5 2
2 4 1 3 5 7
2 3 2 4 6
2 2 1 2
2 2 3 4
2 2 5 6
L  每周的不同日子可以做不同的任务，每个任务要求c_i次，问周一开始最少几天可以满足每个任务的要求。
转化为二维网格，有些格子有标记。每一列（天）最多选e个标记（任务），问最少拿前几列可以使每一行标记数>c_i
注意到越多越好，二分
转化为拿前x列，每一列最多选e个标记，是否可以使每一行标记数>c_i
即 各个星期的数量有限制，各天选任务总量有限制， check每个任务数量是否达到规定。
ana 注意到1.两个主体 列，标记 2.动词：选 且有约束：最多e个。
符合网络流模型  
边权意味着次数。
源汇之间 第一层是列 第二层是标记 ，
i(1层）-j（2层）的边含义：第i周做第j个任务  j-T:第j个任务总共做的次数  S-i 周i可做的任务上限，即day i 一共出现了几次*e
标记到汇的连边 流量上限为
wr 数组大小，longlong，二分写错（65%)
 */