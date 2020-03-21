#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
vector<pair<int,int> >g[maxn];
int ans[maxn];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    s = " " + s;
    int dp[s.size() + 5][2];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][1] = 1;//多付1张(当前这位对应的面值)
    dp[0][0] = 0;//正好
    f1(s.size() - 1) {
        int x = s[i] - '0';
        dp[i][1] = min(dp[i][1], dp[i-1][0] + x + 1);
        dp[i][1] = min(dp[i][1], dp[i-1][1] + 9 - x);//找钱
        dp[i][0] = min(dp[i][0], dp[i-1][1] + 10 - x);//找钱
        dp[i][0] = min(dp[i][0], dp[i-1][0] + x);//直接用x张
    }
    cout << dp[s.size()-1][0] << '\n';
}