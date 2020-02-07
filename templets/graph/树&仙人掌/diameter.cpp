/* 
树的直径
任意一点dfs找到距离它最远的点u，再从u开始dfs找到距离它最远的点v
uv是树的一个直径
输出数的直径
 */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
const int N=222222;
int edgeCount, firstEdge[N],to [N], length[N], nextEdge[N];
vector<int> dist;

void addEdge(int u,int v,int w){
    to[edgeCount]=v;
    length[edgeCount]=w;
    nextEdge[edgeCount]=firstEdge[u];
    firstEdge[u]=edgeCount++;
}

void dfs(int p,int u,int d){
    dist[u]=d;
    for(int iter=firstEdge[u];iter!=-1;iter=nextEdge[iter]){
        if(to[iter]!=p){
            dfs(u,to[iter],d+length(iter));
        }
    }
}
int getDiameter(int nodeCound,
vector <pair<pair<int,int>, int> >edges){//<<u,v>,w> 
    memset(firstEdge,-1,sizeof(firstEdge));
    for(vector pair<pair<int,int>, int> :: iterator
    iter=edges.begin();iter!=edges.end();++iter){
        addEdge(iter->first.first,iter->first.second,iter->second);
        addEdge(iter->first.second,iter->first.first,iter->second);
    }
    dist.resize(nodeCound);
    dfs(-1,0,0);
    int u=max_element(dist.begin(),dist.end())-dist.begin();
    dfs(-1,u,0);
    return *max_element(dist.begin(),dist.end());
}
int main(){
ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}