#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;

typedef long long ll;
ll a[maxn],pre[maxn],suf[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)pre[i]=pre[i-1]+a[i]*a[i];
    for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i];
    ll ans=0;
    rep(i,1,n-1){
      ans=max(ans,pre[i]*suf[i+1]);
    }
    cout<<ans<<endl;
}

/* 
5
2
1
4
3
5
 */