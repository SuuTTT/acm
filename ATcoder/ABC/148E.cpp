#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll num(ll x){

}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n;
    cin>>n;
    cout<<n&1?0:num(n)<<endl;
}
/* 
f[1]=f[2]=1
f[3]=3*1
f[4]=4*1
f[5]=5*3*1
f[6]=6*4*1
trailing zero = n&1?0:num(n)
num(n)
1~n中有多少因子5
 */