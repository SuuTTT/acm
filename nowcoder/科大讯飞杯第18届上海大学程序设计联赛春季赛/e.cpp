#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
long long a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<long long>());
    long long ans=0;
    rep(i,1,n){
        ans+=a[i]-i+1;
    }
    cout<<ans<<endl;
}
/* 
3
3 2 3
 */