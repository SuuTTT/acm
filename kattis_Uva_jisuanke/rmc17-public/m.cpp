#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn],b[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    rep(i,1,n)cin>>a[i];rep(i,1,m)cin>>b[i];
    sort(a+1,a+1+n),sort(b+1,b+1+m);
    int i=n,j=m;
    int ans=0;
    while(i>0&&j>0){
        if(b[j]>=a[i])ans++,i--,j--;
        else i--;
    }
    cout<<ans<<endl;
}