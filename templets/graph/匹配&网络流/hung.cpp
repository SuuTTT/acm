/* 
time O(E*sqrt(V))

n: # of node on one side
g: g[i] is right node that linked to left node i
from: from[i] 左边点i相连的边 in max match  
 */

#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)555;
const int n=100;
vector<int> g[maxn];
int from[maxn],tot;
bool use[maxn];
bool match(int x){
    for(int i=0; i<g[i].size();++i)
    if(!use[g[x][i]]){
        use[g[x][i]]=1;
        if(from[g[x][i]]==-1|| match(from[g[x][i]])){
            from[g[x][i]]=x;
            return 1;
        }
    }
    return 0;
}

int hungary(){
    tot =0;
    memset(from,255,sizeof(from));
    rep(i,1,n){
        memset(use,0,sizeof(use));
        if(match(i))
            ++tot;
    }
    return tot;
}

int main(){
ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}