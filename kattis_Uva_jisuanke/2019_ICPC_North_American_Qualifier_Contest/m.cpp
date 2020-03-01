#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define Decimal fixed<<setprecision(20)
const int maxn=(int)1e6+5;
typedef  double db;
double w,g,h,r;
double f(double x){
    return sqrt(g*g+x*x)+sqrt(h*h+(w-x)*(w-x));
}
double oneThirdIterate(double l,double r,int max_step){
    double ml,mr;
    rep(it,1,max_step){
        ml=(2*l+r)/3,mr=(l+2*r)/3;
        if(f(ml)>f(mr))l=ml;
        else r=mr;
        //debug(f(ml));
    }
    return l;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n){
        cin>>w>>g>>h>>r;
        g-=r,h-=r;
        cout<<Decimal<<sqrt((g-h)*(g-h)+w*w)<<' '<<f(oneThirdIterate(0,w,1000))<<endl;
    }
}
/*
2
1000 100 100 20
100 20 30 2
*/