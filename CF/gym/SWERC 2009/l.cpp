#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
vector<pair<int,int> > p;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        if(n+m==0)break;
        p.clear();
        rep(i,1,n){
            int x,y;
            cin>>x>>x>>x>>y;
            p.push_back({x,y});
        }
        rep(i,1,m){
            int x,y;
            cin>>x>>y;
            int ans=0;
            for(auto t:p){
                if((x<=t.first&&x+y>t.first)||
                (x<t.second&&x+y>=t.second)||
                (t.first<=x&&t.first+t.second>=x+y))
                ans++;
            }
            cout<<ans<<endl;
        }
    }
}
/* 
3 2
3 4 2 5
1 2 0 10
6 5 5 8
0 6
8 2
1 2
8 9 0 10
9 1
10 1
0 0
 */