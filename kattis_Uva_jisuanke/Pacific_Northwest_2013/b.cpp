#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int N,K,M;
typedef long long ll;
const ll inf=(ll)1e18;
ll E[105][105],d[105][105];
bool check(ll x,int n){
    rep(i,1,n)rep(j,1,n)d[i][j]=(E[i][j]<=x?1:inf);
    rep(k,1,n)rep(i,1,n)rep(j,1,n)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    rep(i,1,n)rep(j,1,n)if(d[i][j]>K)return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>N>>K>>M;
        rep(i,1,N)rep(j,1,N)E[i][j]=inf;
        rep(i,1,M){
            int x,y,z;
            cin>>x>>y>>z;x++,y++;
            E[x][y]=z;
            E[y][x]=z;
        }
        rep(k,1,N)rep(i,1,N)rep(j,1,N)
            E[i][j]=min(E[i][j],E[i][k]+E[k][j]);
        ll l=0,r=inf;
        while(l<=r){
            ll mid=l+r>>1;
            if(check(mid,N))r=mid-1;
            else l=mid+1;
        }
        cout<<l<<endl;

    }
}
/* 
2
4 2 4
0 1 100
1 2 200
2 3 300
3 0 400

10 2 15
0 1 113
1 2 314
2 3 271
3 4 141
4 0 173
5 7 235
7 9 979
9 6 402
6 8 431
8 5 462
0 5 411
1 6 855
2 7 921
3 8 355
4 9 113

 */