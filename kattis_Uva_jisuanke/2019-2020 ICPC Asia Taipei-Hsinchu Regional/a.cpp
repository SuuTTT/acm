#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n)cin>>a[i];
    int flag=0;
    rep(i,1,n)rep(j,1,n)rep(k,1,n){
        if(i==j||j==k||k==i)continue;
        if((a[i]-a[j])%a[k]!=0)flag=1;
    }
    cout<<(flag?"no":"yes");
}
/* 
5
1 1 1 1 4
 */