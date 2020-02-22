#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,s;
    cin>>n>>s;
    rep(i,1,n)cin>>a[i];
    int l=1,r=1;
    int ans=n+1,cur=0;
    while(l<=n&&r<=n){
        while(r<=n&&cur<s)cur+=a[r++];
        if(cur>=s)ans=min(ans,r-l);
        while(l<r&&cur>=s)ans=min(ans,r-l),cur-=a[l++];
    }
    cout<<(ans==n+1?0:ans)<<endl;
}
/* 
3 3
1 3 1
6 4
1 2 1 2 3 2
 */