#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
long long n;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n){
        long long cur=1,ans=0;
    while(n){
        n/=2;
        ans+=cur;
        cur*=2;
    }
    cout<<ans<<endl;
    }
    
}