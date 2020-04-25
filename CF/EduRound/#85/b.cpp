#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        vector<ll> a(n);
        rep(i,0,n-1)cin>>a[i];
        sort(a.begin(),a.end());
        int p=0;
        ll sum =0;
        rep(i,0,n-1)if(a[i]<x)p=i;else sum+=a[i];
        if(sum==0){cout<<0<<endl;continue;}
        int ans=n-1-p;
        for(int j=p;j>=0;j--){
            sum+=a[j];ans++;
            //debug(ans);
            if(sum/ans<x)break;
        }
        cout<<ans-(sum/ans<x)<<endl;
    }
}/* 
贪心
 */