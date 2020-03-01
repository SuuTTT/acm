#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
#define PI 3.14159265358979
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){

        double s,r,ans=0;
        cin>>s>>r;
        if(s/2>=r){
            ans=r*r*PI;
        }else{
            if(s*sqrt(2.)/2<=r)ans=s*s;
            else{
                double s1=acos(s/2/r)*2/(2*PI)*r*r*PI-s/2*r*sin(acos(s/2/r));
                ans=PI*r*r-4*s1;
            }
        }
        printf("%.2lf\n",ans);
    }
    
}
/* 
3 
1 1 
8 5 
10 4

 */
