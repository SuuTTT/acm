#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef double db;
db x[3],y[3];
double dis(int i,int j){
    return sqrt((x[i]-x[0])*(x[i]-x[0])+(y[j]-y[0])*(y[j]-y[0]));
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    rep(i,0,2)cin>>x[i]>>y[i];
    db ans=1e20;
    rep(i,1,2)rep(j,1,2)ans=min(ans,dis(i,j));
    if(x[0]>=x[1]&&x[0]<=x[2])ans=min(ans,abs(y[0]-y[1])),ans=min(ans,abs(y[0]-y[2]));
    if(y[0]>=y[1]&&y[0]<=y[2])ans=min(ans,abs(x[0]-x[1])),ans=min(ans,abs(x[0]-x[2]));
    printf("%.10lf\n",ans);
}