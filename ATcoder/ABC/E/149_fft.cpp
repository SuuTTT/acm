#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
using namespace std;

#define debug(x) cout << #x << ": " << x << endl;
#define ll long long
#define mod 1000000007

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}
//A[i] -- x^ 
int main() {

  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);
  vector<int> A(1 << 18, 0);

  ll N, M, num;
  cin >> N >> M;
  for (size_t i = 0; i < N; i++) {
    cin >> num;
    A[num]++;
  }

  // A
  vector<cd> iA;
  for(int i = 0;i < A.size();i++) {
    iA.push_back(cd(A[i], 0));
  }

  fft(iA, false); // FFT(A)

  // FFT(A*A)
  for(int i = 0;i < iA.size();i++) {
    iA[i] = iA[i]*iA[i];
  }

  // A*A
  fft(iA, true);

  ll ans = 0;
  for(int i = 200000;i >=  0;i--) {
    ll freq = round(real(iA[i]));
    // if(freq != 0) {
    //   debug(i);
    //   debug(real(iA[i]));
    // }
    if(freq <= M) {
      ans += freq*1LL*i;
      M -= freq;
    } else {
      ans += M*1LL*i;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
