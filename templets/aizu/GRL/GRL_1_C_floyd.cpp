#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
long long inf=2000000000ll;
long long d[500][500];
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
     rep(i,0,n-1)rep(j,0,n-1)d[i][j]=inf;
     rep(i,0,n-1)d[i][i]=0;
    rep(i,1,m){
        long long x,y,z;
        cin>>x>>y>>z;
        d[x][y]=z;
    }
    rep(k,0,n-1)rep(i,0,n-1)if(d[i][k]!=inf)rep(j,0,n-1)if(d[k][j]!=inf){//negative edges
        if(d[i][k]+d[k][j]<d[i][j])d[i][j]=d[i][k]+d[k][j];
    }
    rep(i,0,n-1)if(d[i][i]<0){
        cout<<"NEGATIVE CYCLE"<<endl;
        return 0;
    }
    rep(i,0,n-1){
        if(d[i][0]==inf)cout<<"INF";else cout<<d[i][0];
        rep(j,1,n-1){
            cout<<' ';
            if(d[i][j]==inf)cout<<"INF";else cout<<d[i][j];
        }
        cout<<endl;
    }
}
/* 
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 7

1 ≤ |V| ≤ 100
0 ≤ |E| ≤ 9900
-2 × 107 ≤ di ≤ 2 × 107
 */