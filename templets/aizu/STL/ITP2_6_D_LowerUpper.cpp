#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n){cin>>a[i];}
    int q;cin>>q;
    while(q--){
        int k;
        cin>>k;
        cout<<lower_bound(a+1,a+1+n,k)-a-1<<' '<<upper_bound(a+1,a+1+n,k)-a-1<<endl;
    }
}
/* 
4
1 2 2 4
3
2
3
5
 */