#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
/* 
golden题
查询一条链上是否有颜色C
Count on tree 模板题
ana1：Dfs+主席树
ana2：树链剖分->一段序列中，是否存在一个数
ana2.1 线段树加set
ana2.2 存这个权值在序列上出现的位置,二分l,r 只要存在x，那么两个数二分的结果应该不相同。
https://www.luogu.com.cn/problemnew/solution/P5838
 */

#define rep(i , a , b) for(int i = (a) ; i <= (b) ; ++i)
#define irep(i , a , b) for(int i = (b) ; i >= (a) ; --i)
#define IO ios::sync_with_stdio(false)
#define ms(A) memset(A , 0 , sizeof A)
#define msinf(A) memset(A , 0x3f , sizeof A)
typedef long long ll;
typedef pair <int , int> pii;

const int inf = 0x3f3f3f3f;
const ll infLL = 0x3f3f3f3f3f3f3f3fLL;

const int N = 100000 + 5;

int n , m , A[N];
int tot , ver[N << 1] , nxt[N << 1] , head[N];
vector <int> p[N];

int f[N] , dep[N] , sz[N] , son[N] , top[N] , num[N] , id[N];

inline void add(int u , int v) {
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

int dfs(int u , int fa) {
    sz[u] = 1; f[u] = fa; dep[u] = dep[fa] + 1;
    for(int i = head[u] , v ; i ; i = nxt[i]) {
        if((v = ver[i]) == fa) continue;
        sz[u] += dfs(v , u);
        if(sz[son[u]] < sz[v]) son[u] = v;
    }
    return sz[u];
}

void Get(int u , int tp) {
    top[u] = tp;
    id[num[u] = ++num[0]] = u;
    if(son[u]) Get(son[u] , tp);
    for(int i = head[u] , v ; i ; i = nxt[i]) {
        if((v = ver[i]) == f[u] || v == son[u]) continue;
        Get(v , v);
    }
}

inline bool query(int u , int v , int k) {
    bool ans = 0;
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u , v);
        if(upper_bound(p[k].begin() , p[k].end() , num[u]) - lower_bound(p[k].begin() , p[k].end() , num[top[u]]))
            return 1;
        u = f[top[u]];
    }
    if(dep[u] < dep[v]) swap(u , v);
    return upper_bound(p[k].begin() , p[k].end() , num[u]) - lower_bound(p[k].begin() , p[k].end() , num[v]);
}

int main() {
    scanf("%d %d" , &n , &m);
    rep(i , 1 , n) scanf("%d" , A + i);
    rep(i , 1  , n - 1) {
        int u , v;
        scanf("%d %d" , &u , &v);
        add(u , v); add(v , u);
    }
    dfs(1 , 0); Get(1 , 1);
    rep(i , 1 , n) p[A[id[i]]].push_back(i);
    rep(i , 1 , m) {
        int u , v , k;
        scanf("%d %d %d" , &u , &v , &k);
        printf("%d" , query(u , v , k));
    }
    return 0;
} 