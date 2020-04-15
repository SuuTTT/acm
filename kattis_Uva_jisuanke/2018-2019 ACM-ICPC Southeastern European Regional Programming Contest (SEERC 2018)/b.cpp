#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef unsigned long long ull;
ull div24(ull fact[]){
    ull ret=1;
     // /24
    rep(i,1,3){
        rep(j,0,2)if(fact[j]%2==0){
            fact[j]/=2;
            break;
        }
    }
    rep(i,0,2)if(fact[i]%3==0){
        fact[i]/=3;
        break;
    }
    rep(i,0,2)ret*=fact[i];
    return ret;
}
ull solve(ull n){
    ull ret=1;
    if(n%2){
        ull fact[3]={n,n-1,n+1};
        ret=div24(fact);
    }else{
        ull fact[3]={n,n-2,n+8};
        ret=div24(fact);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ull a,b,c,n;cin>>a>>b>>c>>n;
    set<ull> s;
    s.insert(a),s.insert(b),s.insert(c);
    ull tm=s.size();
    ull ans=solve(n);
    //debug(ans);
    if(tm==2)ans*=3;
    if(tm==3)ans*=6;
    cout<<ans<<endl;
}
/* 
指针长度是独立的
考虑n个点组成三角形且包含中心。
all-不包含
不包含=三个点都在半圆，方案:
n%2==1: (n * (n-1)/2 * (n-1)/2 )/2 第一个点取法*第二个取法*第三个 第二第三个顺序可交换除二
n%2==0: (n * (n-1)/2 * (n-1)/2 )/2

最后
n%2==1: n,n-1,n+1 /24
n%2==0: n,n-2,n+8 /24
mod 1<<64 用 ull,先除再乘

 */