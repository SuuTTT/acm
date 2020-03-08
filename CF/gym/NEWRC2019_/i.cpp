#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n)cin>>a[i];
    int ok=1;
    rep(i,1,n-1)if(a[i]>a[i+1])ok=0;
    if(ok){
        cout<<1<<' '<<1<<endl;
        return 0;
    }
    int flag=0;
    int i=1;
    while(i<=n-1&&a[i]<=a[i+1])i++;
    while(i>=2&&a[i]==a[i-1])i--;
    //debug(i);
    int j=n;
    while(j>=2&&a[j]>=a[j-1])j--;
    //debug(j);
    while(j<=n-1&&a[j]==a[j+1])j++;
    reverse(a+i,a+1+j);
   // rep(i,1,n)debug(a[i]);
    ok=1;
    rep(i,1,n-1)if(a[i]>a[i+1])ok=0;
    if(ok)cout<<i<<' '<<j<<endl;
    else cout<<"impossible"<<endl;
    
}
/* 
7
10 13 19 19 15 14 20
8
10 13 13 19 15 14 14 20

8
10 13 19 19 15 14 14 20
 */