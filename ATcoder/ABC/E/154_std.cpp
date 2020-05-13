#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

void solve() {
    string S;
    cin >> S;
    ll N, K;
    cin >> K;
    N = S.size();
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(2, vector<ll>(K + 2, 0)));
    dp[0][0][0] = 1;
    rep(i, N) rep(j, 2){
        ll d = j==1?9:S[i] - '0';
        rep(k, K + 1) {
            rep(m, d + 1) {
                dp[i + 1][j == 1 || m < d][k + (m != 0)] += dp[i][j][k];
            }
        }
    }
    ll ans = dp[N][0][K] + dp[N][1][K];
    for(int i=0;i<=N;i++){
       // cout<<dp[i][0][K]<<' '<<dp[i][1][K]<<endl;
    }
    

    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
/* 
#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-x))
typedef long long LL;

int n, K, dp[5][105][3];
char str[105];

int dfs(int m, int use, int limit) {
    if(use > K) return 0;
    if(m > n) return use == K;
    if(dp[use][m][limit] != -1) return dp[use][m][limit];
    int up = limit == 1? str[m]-'0':9, ans = 0;
    for(int i = 0; i <= up; ++i)
        ans += dfs(m+1, use+(i!=0), limit&&i==up); 
    return dp[use][m][limit] = ans;
}

void run_case() {
    cin >> (str+1) >> K;
    n = strlen(str+1);
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0, 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    //cout.setf(ios_base::showpoint);cout.precision(8);
    run_case();
    cout.flush();
    return 0;
}
 */
