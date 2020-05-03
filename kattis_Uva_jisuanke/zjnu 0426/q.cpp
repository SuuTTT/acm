#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn],cnt[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,(n+1)/2)a[i]-=i;
    rep(i,1,n/2)a[n-i+1]-=i;
    int mx=0;
    rep(i,1,n)if(a[i]>=0)cnt[a[i]]++,mx=max(mx,cnt[a[i]]);
    cout<<n-mx<<endl;
    
}
/* 
idea??
5
1 2 3 2 1
6
1 2 3 3 2 1
 */