#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e5+5;
typedef long long ll;
ll a[maxn];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    rep(T,1,t){
        int n;
        cin>>n;
        rep(i,1,n)cin>>a[i];
        sort(a+1,a+1+n);
        ll now=0;
        ll ans=0;
        rep(i,1,n){
            now+=a[i];
            if(now<=a[i]*2)ans++;
            else now-=a[i];
        }
        cout<<"Case #"<<T<<": "<<ans<<endl;
    }
}
/* 
1
5
15 2 1 5 3
*/