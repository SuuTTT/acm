#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
const int C_maxn = 1e6 + 10;
LL CatalanNum[C_maxn];
LL inv[C_maxn];
inline void Catalan_Mod(int N, LL mod)
{
    inv[1] = 1;
    for(int i=2; i<=N+1; i++)///线性预处理 1 ~ N 关于 mod 的逆元
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;

    CatalanNum[0] = CatalanNum[1] = 1;

    for(int i=2; i<=N; i++)
        CatalanNum[i] = CatalanNum[i-1] * (4 * i - 2) %mod * inv[i+1] %mod;
}
stack<int>S;
int cnt[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    Catalan_Mod(n,(ll)1e9+7);
    rep(i,1,n){
        int x;
        cin>>x;
        S.push_back(x);
    }
    while(!S.empty()){
        int now=S.top();
    }
}
/* 
6
3
1
6
2
4
5
 */