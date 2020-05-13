#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
const int inf=(long long)1e9+5;
int a[maxn],dp[maxn],tmp[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n)cin>>a[i];
    fill(tmp,tmp+n+2,inf),tmp[0]=-1;
    int ans=0;
    rep(i,1,n){
        int p=lower_bound(tmp,tmp+ans+1,a[i])-tmp;
        ans=max(ans,p);
        tmp[p]=min(a[i],tmp[p]);
    }
    rep(i,1,ans)debug(tmp[i]);
    cout<<ans<<endl;
}
/* 
5
5
1
3
2
4

1 0
 */