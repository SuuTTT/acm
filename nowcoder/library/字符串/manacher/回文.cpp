#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long uLL;
#define ls rt<<1
#define rs rt<<1|1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define bug printf("*********\n")
#define FIN freopen("input.txt","r",stdin);
#define FON freopen("output.txt","w+",stdout);
#define IO ios::sync_with_stdio(false),cin.tie(0)
#define debug1(x) cout<<"["<<#x<<" "<<(x)<<"]\n"
#define debug2(x,y) cout<<"["<<#x<<" "<<(x)<<" "<<#y<<" "<<(y)<<"]\n"
#define debug3(x,y,z) cout<<"["<<#x<<" "<<(x)<<" "<<#y<<" "<<(y)<<" "<<#z<<" "<<z<<"]\n"
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const LL INFLL = 1e18;
const int mod = 1e9 + 7;
const double Pi = acos(-1);
LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}
LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}
double dpow(double a, LL b) {
    double ans = 1.0;
    while(b) {
        if(b % 2)ans = ans * a;
        a = a * a;
        b /= 2;
    } return ans;
}
LL quick_pow(LL x, LL y) {
    LL ans = 1;
    while(y) {
        if(y & 1) {
            ans = ans * x % mod;
        } x = x * x % mod;
        y >>= 1;
    } return ans;
}
LL del[maxn], add[maxn];
LL pre[maxn], suf[maxn],pre1[maxn], suf1[maxn];
LL suml[maxn], sumr[maxn];
char str[maxn], s[maxn];
int n, m;
int p[maxn];
void manacher() {
    m = 0;
    s[m] = '#';
    for(int i = 1; i <= n; i++) {
        s[++m] = str[i];
        s[++m] = '#';
    }
    s[++m] = '\0';
    int mx = 0, id = 0;
    for(int i = 0; i <= m; i++) {
        if(mx > i) p[i] = min(p[2 * id - i], mx - i);
        else p[i] = 1;
        while(i - p[i] >= 0 && i + p[i] <= m && s[i - p[i]] == s[i + p[i]]) p[i]++;
        if(i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    //FIN
#endif
    scanf("%s", str + 1);
    n = strlen(str + 1);
    manacher();
    for(int i = 0; i < 26; i++) {
        scanf("%lld %lld", &del[i], &add[i]);
    }
    for(int i = 1; i <= n; i++) {
        suml[i] = suml[i - 1] + del[str[i] - 'a'];
        pre[i] = pre[i - 1] + add[str[i] - 'a'];
        pre[i] = min(pre[i], suml[i]);
        //pre1[i] = pre1[i - 1] + min(del[str[i] - 'a'],add[str[i] - 'a']);
        //cout<<pre[i]<<' '<<pre1[i]<<endl;
    }
    for(int i = n; i >= 1; i--) {
        sumr[i] = sumr[i + 1] + del[str[i] - 'a'];
        suf[i] = suf[i + 1] + add[str[i] - 'a'];
        suf[i] = min(suf[i], sumr[i]);
        //suf1[i] = suf1[i + 1] + min(del[str[i] - 'a'],add[str[i] - 'a']);
    }
    LL ans = INFLL;
    for(int i = 0; i <= m; i++) {
        p[i]--;
        if(i % 2 == 0) {
            int x = p[i] / 2;
            int l = i / 2 - x + 1;
            int r = i / 2 + x;
            ans = min(ans, suml[l - 1] + suf[r + 1]);
            ans = min(ans, pre[l - 1] + sumr[r + 1]);
        } else {
            int x = p[i] / 2;
            int l = i / 2 - x + 1;
            int r = i / 2 + x + 1;
            ans = min(ans, suml[l - 1] + suf[r + 1]);
            ans = min(ans, pre[l - 1] + sumr[r + 1]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
/* 
给你一个字符串，你可以进行如下操作
删除字符串的第一个字母。
删除字符串的最后一个字母。
在字符串的头部添加任意一个你想要的字母。
在字符串的尾部添加任意一个你想要的字母。
每次操作的代价是根据字母来定的，问你将字符串变成一个回文串所需要的最小花费
ana:
pre[i]: 将前i个字符变成回文串的最小花费。
对于某字符，要使它成为回文串的一部分，一个是删除，一个是在另一端加上对应的字符。
由于只能在两端操作，删字符必须在加之前。所以正确的写法是
suml[i] = suml[i - 1] + del[str[i] - 'a'];
pre[i] = pre[i - 1] + add[str[i] - 'a'];
pre[i] = min(pre[i], suml[i]);
而非pre1[i] = pre1[i - 1] + min(del[str[i] - 'a'],add[str[i] - 'a']);
 */