#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1995;
const int maxm=(int)1e6;
//有向无向皆可
/* 
POJ1041
先判定：无向图：所有点度数为偶数，有向图：所有点出入度相同。
然后利用性质：欧拉回路G中去掉一个圈，得到的G'任然是欧拉回路。

欧拉路径和欧拉回路的算法类似，不同在于有解判定和初始点选择，
且去圈最后会剩下一条路径
 */
int father[maxn];
vector< pair<int,int> > adj[maxn];
bool vis[maxm];
int getFather(int x){
    return x==father[x]?x:father[x]=getFather(father[x]);
}
void add(int x,int y,int z){
    adj[x].push_back({z,y});
    adj[y].push_back({z,x});
}
vector<int > path;
#define eid first
#define vtx second
void dfs(int u){
    for(int it=0;it<adj[u].size();it++)if(!vis[adj[u][it].eid]){
        pair<int,int> v=adj[u][it];
        vis[v.eid]=1;
        dfs(v.vtx);
        path.push_back(v.eid);
    }
}
#undef eid
#undef vtx

bool solve(){
    for(int i=1;i<maxn;i++)father[i]=i;
    //并查集的merge
    for(int i=1;i<maxn;i++){
        for(int j=0;j<adj[i].size();j++){
            pair<int,int> v=adj[i][j];
             father[getFather(i)]=getFather(v.second);  
        }
    }
    int origin=-1;
    //判存在性，并且保证字典序最小
    for(int i=0;i<maxn;i++)if(adj[i].size()){
        if(adj[i].size()%2==1)return 0;
        if(origin==-1)origin=i;
        if(getFather(i)!=getFather(origin))return 0;
        //字典序最小。
        sort(adj[i].begin(),adj[i].end());
    }
    path.clear();
    memset(vis,0,sizeof(vis));
    if(origin!=-1)dfs(origin);
    reverse(path.begin(),path.end());
    return 1;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x,y,z;
    while(cin>>x>>y){
        if(x==0&&y==0)break;
        rep(i,1,maxn-1)adj[i].clear();
        cin>>z;
        add(x,y,z);
        while(cin>>x>>y){
             if(x==0&&y==0)break;
            cin>>z;
            add(x,y,z);
        }
        if(solve()){for(int i=0;i<path.size();i++)cout<<path[i]<<' ';cout<<endl;}
        else cout<<"Round trip does not exist."<<endl;
    }

}