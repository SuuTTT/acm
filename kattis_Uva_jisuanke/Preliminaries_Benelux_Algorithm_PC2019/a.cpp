#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn],b[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int r,c;
    cin>>r>>c;

    rep(i,1,r)cin>>a[i];
    rep(i,1,c)cin>>b[i];
    debug(max_element(a+1,a+r+1));
    if(*max_element(a+1,a+r+1)==*max_element(b+1,b+c+1))cout<<"possible"<<endl;
    
    else cout<<"impossible"<<endl;

}
/* 
A2B1A2B2A1A2A2A2
 */