#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define Decimal fixed<<setprecision(20)
const int maxn=(int)1e6+5;
double a[maxn],b[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n){cin>>a[i];b[i]=a[i];}
    rep(i,1,n){a[i]+=a[i-1];}
    for(int i=n;i>=1;i--)b[i]+=b[i+1];
    double ans=0;
    rep(i,1,n)a[i]/=i,b[i]/=(n-i+1),ans=max(ans,a[i]),ans=max(ans,b[i]);
    cout<<Decimal<<ans<<endl;
    
}
/* 5
10 10 -10 -4 10 */