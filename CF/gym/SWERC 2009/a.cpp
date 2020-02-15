#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define Decimal fixed<<setprecision(20)
const int maxn=(int)1e6+5;
typedef double db;
pair<db,db> p[maxn];
#define pdd pair<db,db>
#define x first
#define y second
int n,m;
double f(double xx){
    db ret=0;
    rep(i,1,n){
        double dis=(p[i].x-xx)*(p[i].x-xx)+(p[i].y)*p[i].y;
        if(ret<dis)ret=dis;
    }
    return ret;
}
double oneThirdIterate(double l,double r,int max_step){
    double ml,mr;
    rep(i,1,max_step){
        ml=(2*l+r)/3,mr=(l+2*r)/3;
        if(f(ml)>f(mr))l=ml;
        else r=mr;
        //debug(f(ml));
    }
    return l;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    double x,y;
    while(cin>>n){
        if(n==0)break;
        db mx=1e-18,mn=1e18;
        rep(i,1,n){
            scanf("%lf%lf",&p[i].x,&p[i].y);
            //cin>>p[i].x>>p[i].y;
            mx=max(mx,p[i].x),mn=min(mn,p[i].x);
        }
        double xx=oneThirdIterate(mn,mx,75);
       // cout<<Decimal<<xx<<' '<<sqrt(f(xx))<<endl;
       printf("%.20lf %.20lf\n",xx,sqrt(f(xx)));
    }
}
/* 
2
1.5 1.5
3 0

1
0 0

4
1 4
4 4
-3 3
2 4

5
4 7
-4 0
7 -6
-2 4
8 -5

 */