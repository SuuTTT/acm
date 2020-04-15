#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e3+5;
typedef long long ll;
ll g[maxn][maxn];
int main(){
    int n;cin>>n;
    int m=n*(n-1)/2;
    rep(i,1,m){
        int x,y,z;cin>>x>>y>>z;
        g[x][y]=g[y][x]=z;
    }
    ll ans=0;
    rep(i,1,n){
        vector<ll> V;
        rep(j,1,n)if(i!=j)V.push_back(g[i][j]);
        sort(V.begin(),V.end());
        rep(i,0,V.size()-1)if(i&1)ans+=V[i];
    }  
    cout<<ans<<endl;

}

/* 
欧拉回路构造

3
1 2 1
2 3 1
3 1 1

 */