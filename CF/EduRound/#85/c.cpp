#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll a[maxn],b[maxn],c[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        
        rep(i,1,n){
            ll x,y;cin>>a[i]>>b[i];
        }
        b[0]=b[n];
        ll ans=0,mn=1e18;
        rep(i,1,n)c[i]=max(0ll,a[i]-b[i-1]),ans+=c[i],mn=min(mn,a[i]-c[i]);
        cout<<ans+mn<<endl;
    }
}
/* 
1
3
7 15
2 14
5 3
连锁反应
二分
如何check？
考虑最终状态，除了最后一个，每个人都造成了死亡伤害。
枚举即可，不用二分

问题想错了
 */