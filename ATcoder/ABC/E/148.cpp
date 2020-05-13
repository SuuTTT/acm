#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n;cin>>n;
    if(n%2)cout<<0<<endl;
    else{
        n/=2;
        long long ans=0;
        while(n){
            ans+=n/5;n/=5;
        }
        cout<<ans<<endl;
    }
}
/* 
5   5*3*1
6   6*4*2*1
25 /5=5  5/5=1
 */