/*
 * @Date         : 2020-04-19 00:53:23
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int t, k, c[10], v[10], m;
string s;
bool dfs(int num, int k)
{
    if (num == -1) {
        if (k != 0)
            return 0;
        if (m % 3 != 0)
            return 0;
        return 1;
    }
    int tmp = min(v[num], k);
    for (c[num] = tmp; c[num] >= max(tmp - 2, 0); c[num]--) {
        m += c[num] * num;
        if (dfs(num - 1, k - c[num]))
            return 1;
        m -= c[num] * num;
    }
    return 0;
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> s >> k;
        memset(c, 0, sizeof(c));
        memset(v, 0, sizeof(v));
        m = 0;
        for (int i = 0; i < s.length(); i++)
            v[s[i] - '0']++;
        int flag = dfs(9, k);
        if (flag) {
            int z = 1;
            for (int i = 9; i >= 0; i--) {
                if (c[i] && i)
                    z = 0;
                if (i == 0 && z == 1 && k != 1) {
                    cout << -1;
                    break;
                }
                for (int j = 0; j < c[i]; j++)
                    cout << i;
            }
        }
        else
            cout << -1;
        cout << endl;
    }
}