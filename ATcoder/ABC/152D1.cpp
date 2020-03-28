#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = (int) 3e5 + 5;
const int M = (int) 998244353;

typedef long long ll;

int n;
ll a[10][10];

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x = i;
        int y = x % 10;
        while (x > 9) x /= 10;
        a[x][y]++;
    }

    long long res = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            res += a[i][j] * a[j][i];

    cout << res << endl;

    return 0;
}
