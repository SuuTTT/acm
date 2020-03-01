#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,0,n-1){cin>>a[i];}
    int q;cin>>q;while(q--){
        int l,m,r;
        cin>>l>>m>>r;
        rotate(a+l,a+m,a+r);
    }
    rep(i,0,n-1){cout<<a[i]<<(i==n-1?'\n':' ');}
}
/* 
rotate(b,m,e): For each integer kk (0≤k<(e−b)), 
move element b+kb+k to the place of element b+((k+(e−m))mod(e−b))).
[b,e)区间的数绕环，转到m为首。
 */