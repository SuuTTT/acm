#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n)cin>>a[i];
    int q;cin>>q;
    while(q--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op)cout<<*max_element(a+l+1,a+r+1)<<endl;
        else cout<<*min_element(a+l+1,a+r+1)<<endl;
    }
}
/* 
- min(b,eb,e): report the minimum element in ab,ab+1,...,ae−1ab,ab+1,...,ae−1
- max(b,eb,e): report the maximum element in ab,ab+1,...,ae−1

7
8 3 7 1 9 1 4
3
0 0 3
0 1 5
1 0 7
 */