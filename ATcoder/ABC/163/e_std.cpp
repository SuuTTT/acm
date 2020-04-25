#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<long long int, int>>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	vector<vector<long long int>>dp(N + 2, vector<long long int>(N + 2));
	for (int i = 0; i < N; i++) {
		int len = N - i + 1;
		for (int j = 0; j + len < N + 2; j++) {
			dp[j + 1][j + len] = max(dp[j + 1][j + len], dp[j][j + len] + v[i].first*abs(v[i].second - (j + 1)));
			dp[j][j + len - 1] = max(dp[j][j + len - 1], dp[j][j + len] + v[i].first*abs(v[i].second - (j + len - 1)));
		}
	}
	long long int ans = 0;
	for (int i = 0; i < N + 1; i++) {
		ans = max(ans, dp[i][i + 1]);
	}
	cout << ans << endl;
}
