#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int n,m;
vector<int> E[maxn],ans;
int vis[maxn];
int ind[maxn];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,1,m){
        int x,y;
        cin>>x>>y;
        E[x].push_back(y);
        ind[y]++;
    }
    queue<int> Q;
    rep(i,0,n-1)if(!ind[i])Q.push(i);
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        vis[now]=1;
        ans.push_back(now);
        for(auto t:E[now]){
            if(vis[t])continue;
            ind[t]--;
            if(ind[t]==0)Q.push(t);
        }
    }
    for(auto t:ans)cout<<t<<endl;
    //cout<<endl;
}
/* 
当做n-1 次后还有点没进输出队列 那么这些点就是环上的 
因为环上的各点入度都为1 没有0的 就不能更新。
6 6
0 1
1 2
3 1
3 4
4 5
5 2
 */