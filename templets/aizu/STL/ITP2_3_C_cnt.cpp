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
        int val,l,r;
        cin>>l>>r>>val;
        cout<<count(a+l+1,a+r+1,val)<<endl;
    }
}
/* 

count(b,e,kb,e,k): print the number of the specific values kk in ab,ab+1,...,ae−1ab,ab+1,...,ae−1.
9
1 4 1 4 2 1 3 5 6
3
0 9 1
1 6 1
3 7 5
 */