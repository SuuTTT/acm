#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define debug(x) cerr<<#x<<": "<<x<<endl
const int inf=0x3f3f3f3f;
int T;
int main(){
//    scanf("%d",&T);
    T=1;
    for(int cas=1;cas<=T;cas++){
        double a[5];
        for(int i=0;i<4;i++)scanf("%lf",&a[i]);
        sort(a,a+4);
        double t;
        scanf("%lf",&t);
        double x=3*t-a[1]-a[2];
        if(x<a[0])printf("impossible\n");
        else if(x>a[3]||fabs(x-a[3])<1e-5)printf("infinite\n");
        else {
            printf("%.2lf\n",x);
        }
    }
    return 0;
}
/*

*/