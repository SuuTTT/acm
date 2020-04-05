#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef double db;
const double pi=acos(-1.0);
double r1,r2;
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>r1>>r2;
        //if(r1<r2)swap(r1,r2);
       
        db theta=atan((r1+r2)/r1);
        db a=pi-theta*2;
        db b=pi/2-a;
        db c=theta-b;
        //debug(theta),debug(a),debug(b),debug(c);
        //debug(r1*(r1+r2)/2),debug(r1*sin(a)*r1/2),debug(b*r1*r1),debug(r2*r2*c);
        db ans=r1*(r1+r2)/2-r1*sin(a)*r1/2-b*r1*r1/2-r2*r2*c/2;
        printf("%.20lf\n",ans);
    }
}
/* 
2
10 5
5 10
 */