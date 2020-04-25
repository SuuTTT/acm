#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int flag=1;
        int lx=0,ly=0;
        rep(i,1,n){
            int x,y;cin>>x>>y;
            int tmpx=x-lx,tmpy=y-ly;
            if(tmpx<0||tmpy<0||tmpx<tmpy)flag=0;
            //debug(tmpx),debug(tmpy);
            lx=x,ly=y;
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
}