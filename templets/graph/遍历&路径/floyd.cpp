#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)111;
const int INF=(int)1e9;
void floid(){
    rep(k,1,n)rep(i,1,n)rep(j,1,n)
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
int main(){}