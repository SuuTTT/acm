#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long double n;cin>>n;
    if(n>13){cout<<"2.718281828459"<<endl;return 0;}
    long double cur=1;
    long double e=1;
    rep(i,1,n){
        cur*=(long double)i;
        debug(cur);
        e+=(long double)1./cur;
    }
    printf("%.20Lf",e);
    //cout<<e<<endl;
}