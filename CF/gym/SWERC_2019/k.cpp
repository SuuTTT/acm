#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
set<int> S[maxn];
int n,m,t,v;
vector<int> E[maxn],fa,ans;
void dfs(int u){
    if(S[u].size()>=2)return;
    if(S[u].count(v))return; 
    S[u].insert(v);
    for(auto t:E[u])dfs(t);
}
void init(){
    rep(i,1,m){
        int x,y;
        cin>>x>>y;
        if(y==t){
            fa.push_back(x);
        } else E[y].push_back(x);//rev
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>t;
    init();
    for(auto t:fa)v=t,dfs(t);
    for(auto t:fa){
        if(S[t].size()==1)ans.push_back(t);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto t:ans)cout<<t<<endl;
}
/* 
3 3 2
0 1
0 2
1 2
 */