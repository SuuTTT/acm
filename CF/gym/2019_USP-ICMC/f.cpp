#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define Decimal fixed<<setprecision(20)
const int maxn=(int)1e6+5;
typedef double db;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    double n;
    cin>>n;
    db ans=0;
    rep(i,1,2000){
        //ans+=pow((n-1)/n,i)*min(i*1.0,n)/(n-1);
        
    }
    
    db cal=(n+1)*n/2/n;
    
    cout<<Decimal<<cal<<endl;
}