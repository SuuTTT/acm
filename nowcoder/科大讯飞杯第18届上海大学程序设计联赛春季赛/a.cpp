#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a[4];
    rep(i,0,3)cin>>a[i];
    sort(a,a+4);
    int ans=1e9;
    do{
        ans=min(ans,(int)abs(a[0]+a[1]-a[2]-a[3]));
        //rep(i,0,3)cout<<a[i]<<' ';
        //cout<<endl;
    }
    while(next_permutation(a,a+4));
    cout<<ans<<endl;
}