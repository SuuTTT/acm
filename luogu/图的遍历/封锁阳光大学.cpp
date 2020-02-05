#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
//任意图的最小点覆盖，每条边必须有且仅有一个端点被选
/* 
分析：对于某条边，要么左端点 要么右端点。
任选一条边开始，可以递推下去，与黑白染色的过程相同。
算法：
黑白染色，可以染就取数量少的。
不可以就impossible

wa:bool dfs 的返回情况，
1.&&  ts&=dfs;  return ts;  
2.|| if(dfs)return 1;  这样写的话一个返回1就不会执行剩下的同层的节点了。
 */
vector<int> E[maxn];
int vis[maxn];
vector<int> tmp;
bool dfs(int v,int color){
    //debug(v);
    vis[v]=color;
    tmp.push_back(v);
    bool ts=1;
    for(auto t:E[v]){
        if(vis[t]==-color)continue;
        if(vis[t]==color)return 0;
        if(vis[t]!=0)continue;
        
        ts&=dfs(t,-color);
    
    }
    return ts;
}
int main(){
    int n,m;
    cin>>n>>m;
    rep(i,1,m){
        int x,y;
        cin>>x>>y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    int flag=1;
    int ans=0;
    rep(i,1,n){
        if(vis[i])continue;
        //for(auto t:tmp)debug(t);
        tmp.clear();
        if(dfs(i,i)==0){flag=0;break;}
        int tot=0;
        for(auto t:tmp)if(vis[t]==i)tot++;
        ans+=min(tot,(int)tmp.size()-tot);
   }
  // rep(i,1,n)debug(vis[i]);
    if(flag==0)cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
}
/*

4 3
1 4
2 4
3 4

5 4
1 5
2 5
3 5
4 5


7 5
1 2
2 3
3 4
5 6
6 7


3 3
1 2
1 3
2 3
*/