#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<bitset>
#include<ctime>
#include<deque>
#include<stack>
#include<sstream>
typedef long long ll;
using namespace std;
typedef unsigned long long int ull;
#define maxn 60005
#define ms(x) memset(x,0,sizeof(x))
#define Inf 0x7fffffff
#define inf 0x3f3f3f3f
const long long int mod = 1e9 + 7;
#define pi acos(-1.0)
#define pii pair<int,int>
#define eps 1e-7
#define pll pair<ll,ll>



ll quickpow(ll a, ll b) {
    ll ans = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2)ans = ans * a;
        b = b / 2;
        a = a * a;
    }
    return ans;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int n, m;
map<string, int>mp;
int vis[1000][1000][20];
int id = 1;
int iseg[1000][1000];
int haseg[1000][1000];

void num(string s) {
    if (mp.count(s))return;
    else mp[s] = id++;
}

void bfs(int x) {
    queue<pii>q;
    vis[x][x][0] = 1;
    q.push({ x,0 });
    while (!q.empty()) {
        pii tmp = q.front();
        q.pop();
        for (int i = 1; i < id; i++) {
            if (iseg[tmp.first][i] && !vis[x][i][tmp.second]) {
                vis[x][i][tmp.second] = 1;
                q.push({ i,tmp.second });
            }
            if (haseg[tmp.first][i] && !vis[x][i][1]) {
                vis[x][i][1] = 1;
                q.push({ i,1 });
            }
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    cin >> n >> m;
    int i, j;
    while (n--) {
        string a, b, c;
        cin >> a >> b >> c;
        num(a);
        num(c);
        if (b[0] == 'i') {
            iseg[mp[a]][mp[c]] = 1;
        }
        else {
            haseg[mp[a]][mp[c]] = 1;
        }
    }
    for (i = 1; i < id; i++)bfs(i);
    for (i = 1; i <= m; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        if (b[0] == 'i') {
            printf("Query %d: %s\n", i, vis[mp[a]][mp[c]][0] ? "true" : "false");
        }
        else {
            printf("Query %d: %s\n", i, vis[mp[a]][mp[c]][1] ? "true" : "false");
        }
    }

}
/* 
4 1
a has-a b
b has-a c
a is-a d
d is-a c
a has-a c
2 6
b has a
a has b
a has a
b has b
a has b
a is b
 */