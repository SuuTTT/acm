#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
#include <cmath>
#include <stack>
#include <sstream>
#include <list>
#include <assert.h>
#include <bitset>
#include <numeric>
#define debug() puts("++++")
#define gcd(a, b) __gcd(a, b)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define fi first
#define se second
#define pb push_back
#define sqr(x) ((x)*(x))
#define ms(a,b) memset(a, b, sizeof a)
#define sz size()
#define be begin()
#define ed end()
#define pu push_up
#define pd push_down
#define cl clear()
#define lowbit(x) -x&x
#define all 1,n,1
#define FOR(i,n,x)  for(int i = (x); i < (n); ++i)
#define freopenr freopen("in.in", "r", stdin)
#define freopenw freopen("out.out", "w", stdout)
using namespace std;
  
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL LNF = 1e17;
const double inf = 1e20;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxn = 1e6 + 7;
const int maxm = 2000000 + 7;
const LL mod = 1e9 + 7;
const int dr[] = {-1, 1, 0, 0, 1, 1, -1, -1};
const int dc[] = {0, 0, 1, -1, 1, -1, 1, -1};
int n, m;
inline bool is_in(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}
 
vector<string> v;
 
struct Query{
    int id, l, r;
    bool operator == (const Query &q){
        return q.l == l && q.r == r;
    }
};
vector<Query> q;
vector<vector<int>> f;
 
void getFail(const string &s, vector<int> &f){
    f[0] = f[1] = 0;
    for(int i = 1; i < s.sz; ++i){
        int j = f[i];
        while(j && s[i] != s[j])  j = f[j];
        f[i+1] = s[i] == s[j] ? j+1 : 0;
    }
}
 
 
int solve(const string &s1, const string& s2, const vector<int> &f){
    int j = 0;
    for(int i = 0; i < s1.sz; ++i){
        while(j && s1[i] != s2[j])  j = f[j];
        if(s1[i] == s2[j])  ++j;
        if(i + 1 == s1.sz)  return j;
        if(j == s2.sz)  j = f[j];
    }
    return 0;
}
 
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        string s;  cin >> s;
        f.pb(vector<int>(s.sz+1, -1));
        v.pb(move(s));
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        int l, r;  cin >> l >> r;
        q.pb((Query){i, l-1, r-1});
    }
    vector<int> ans;
    ans.resize(q.sz);
    sort(q.be, q.ed, [&](Query ql, Query qr){return ql.l < qr.l || ql.l == qr.l && ql.r < qr.r;});
    for(int i = 0; i < q.sz; ++i){
        Query &qq = q[i];
        if(i && q[i] == q[i-1])  ans[qq.id] = ans[q[i-1].id];//去重
        else{
            if(f[qq.r][0] < 0)
                getFail(v[qq.r], f[qq.r]);
            ans[qq.id] = solve(v[qq.l], v[qq.r], f[qq.r]);
        }
    }
    for(auto &x : ans)  printf("%d\n", x);
    return 0;
}