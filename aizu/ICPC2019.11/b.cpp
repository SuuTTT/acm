#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int mp[51][51],mx[51][51],mn[51][51];

int main(){
   // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int w,d,n;
    cin>>w>>d>>n;
    rep(ii,1,w)rep(jj,1,d)mx[ii][jj]=1000,mn[ii][jj]=-1000;
    rep(i,1,n){
        int x,y,z;
        cin>>x>>y>>z;
        mp[x][y]=z;
        rep(ii,1,w)rep(jj,1,d){
            int d=abs(x-ii)+abs(y-jj);
            mx[ii][jj]=min(mx[ii][jj],z+d);
            mn[ii][jj]=max(mn[ii][jj],z-d);
        }
    }
    int flag=1;
    rep(ii,1,w)rep(jj,1,d){
        if(mx[ii][jj]<mn[ii][jj])flag=0;
        if(mp[ii][jj]==0)mp[ii][jj]=mn[ii][jj];
    }
    int ans=0;
     rep(ii,1,w)rep(jj,1,d)ans+=mp[ii][jj];
     if(flag)cout<<ans<<endl;
     else cout<<"No"<<endl;


}
/* 
5 4 2
1 1 10
5 4 3
 */