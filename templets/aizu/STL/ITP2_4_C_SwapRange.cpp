#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int b,e,t;
    int n;
    cin>>n;
    rep(i,1,n)cin>>a[i];
    int q;cin>>q;
    while(q--){
        int b,e,t;
        cin>>b>>e>>t;
        swap_ranges(a+b+1,a+e+1,a+t+1);
    }
    rep(i,1,n)cout<<a[i]<<(n==i?'\n':' ');
    


}
/* 
swapRange(b,e,t): For each integer kk (0≤k<(e−b)0≤k<(e−b), swap element (b+k)(b+k) and element (t+k)(t+k).
11
1 2 3 4 5 6 7 8 9 10 11
1
1 4 7
 */