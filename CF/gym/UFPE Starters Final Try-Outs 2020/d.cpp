#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
typedef double db;
const int maxn=(int)1e5+5;
const db eps=1e-7;
db sx,sy;
struct cyc{
    db x,y,r;
    db dis;
    void read(){cin>>x>>y>>r;}
    db calDis(){return sqrt((x-sx)*(x-sx)+(y-sy)*(y-sy));}
    operator < (const cyc& R) const{
        return dis-r<R.dis-R.r;
    }
}c[maxn];
int main(){
    int n;
    
    cin>>n>>sx>>sy;
    rep(i,1,n)c[i].read(),c[i].dis=c[i].calDis();
    sort(c+1,c+1+n);
    db nowr=0;
    db ans=0;
    rep(i,1,n){
        db delta = c[i].dis-c[i].r-nowr;
        if(delta<eps){
            nowr+=c[i].r;
        }
        else{
            ans+=delta;
            nowr+=delta;
            nowr+=c[i].r;
        }
    }
    printf("%.20lf\n",ans);

}