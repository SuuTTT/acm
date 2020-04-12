#include<bits/stdc++.h>
using namespace std;
 
using i32 = int_fast32_t;
using i64 = int_fast64_t;
 
int main() {
    i32 n, k;
    cin >> n >> k;
    vector<i64> a(n+1);
    for (i32 i = 1; i < n+1; i++) cin >> a[i];
    partial_sum(begin(a), end(a), begin(a));
 
    i32 ans = 0;
    map<i32, i32> count;
    for (i32 i = 0; i < n+1; i++) {
        if (i >= k) count[(a[i-k] - (i-k)) % k]--;
        ans += count[(a[i] - i) % k]++;
    }
 
    cout << ans << endl;
}
/* 
5 4
1 4 2 3 5
 */