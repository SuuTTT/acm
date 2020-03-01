#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn],b[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;rep(i,0,n-1)cin>>a[i];
    int m;cin>>m;rep(i,0,m-1)cin>>b[i];
    cout<<includes(a,a+n,b,b+m)<<endl;
}
/* 
4
1 2 3 4
2
2 4
 */