#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string mp[105];
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int h,w;cin>>h>>w;
    rep(i,1,h)cin>>mp[i-1];
    double gc=0,num;
    rep(i,0,h-1)rep(j,0,w-1)if(mp[i][j]!='.'){
      gc+=j+0.5;
      num++;
    }
    gc/=num;
    double left=0,right=0;;
    rep(j,0,w-1)if(mp[h-1][j]!='.')right=j;
    right+=1;
    for(int j=w-1;j>=0;j--)if(mp[h-1][j]!='.')left=j;
    int flag=0;
    //debug(gc),debug(right),debug(left);
    if(left-gc>1e-6){puts("left");}
    else if(gc-right>1e-6)puts("right");
    else puts("balanced");

}
/* 
3 3
...
.__
.|.
题目细节
 */