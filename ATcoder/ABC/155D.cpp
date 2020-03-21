#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
 
 
const long long INF = 1e18;
 
bool f(long long x, long long y, vector<long long> &A, int n) {//越小越好
    long long s = 0;//小于x的数有几个
    for (int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        if (A[i] >= 0) {
            while (l <= r) {
                int m = (l+r) / 2;
                if (A[i]*A[m] < x) l = m+1;
                else r = m-1;
            }
            s += r+1;
        } else {
           while (l <= r) {
                int m = (l+r) / 2;
                if (A[i]*A[m] < x) r = m-1;
                else l = m+1;
            }
            s += n-l;
        }
        if (A[i]*A[i] < x) s--;
    }
    s /= 2;
    return s < y;
}
 
int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    long long l = -INF-5, r = INF+5;
    while(l<= r) {
        long long m = (l+r) / 2;
        if (f(m, K, A, N)) l = m+1;
        else r = m-1;
    }
    cout << r << endl;
    return 0;
}
/* 
4 3
-4 -2 3 3
 
10 40
5 4 3 2 -1 0 0 0 0 0
 */