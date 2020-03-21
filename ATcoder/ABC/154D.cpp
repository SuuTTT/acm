#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
long long a[maxn];
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    rep(i,1,n){
        cin>>a[i];
    }
    double ans=0,cur=0;;
    rep(i,1,k)cur+=a[i]+1;ans=cur;
    rep(i,k+1,n){
        
        cur+=a[i]+1;
        cur-=(a[i-k]+1);
        ans=max(ans,cur);
    }
    printf("%.3lf",ans/2);
    //cout<<ans/2<<endl;
}
/* 
5 3
1 2 2 4 5

10 4
17 13 13 12 15 20 10 13 17 11

 */