#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1995;
const int maxm=(int)1e6;
/* 
分析：题意等价于给n条边，找一个有n+1节点的链,多届取字典序最小。
单一解只要从入度为0的点遍历即可。
这里多解当且仅当形成一个环，一共2500个点，可以直接排序得到。
wa1：fix了aa的样例，不知道哪里错了。v2:fix错了
wa2: rho 型的路径，

代码：有的循环必须要dfs，而且码量一样的。

正解是欧拉回路&路版题
 */


string s;

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
vector<int > path,node;
#define eid first
#define vtx second
void dfs(int u){
    for(int it=0;it<adj[u].size();it++)if(!vis[adj[u][it].eid]){
        pair<int,int> v=adj[u][it];
        vis[v.eid]=1;
        dfs(v.vtx);
        path.push_back(v.eid);
        node.push_back(v.vtx);
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
string input[maxm];
int main(){
    int n;
    cin>>n;
    rep(i,1,n){
        string s;
        cin>>input[i];
        s=input[i];
        int x=s[0],y=s[1];
        add(x,y,i);
        //if(x==y)f[x]=1;
        //st.insert(x);st.insert(y);
    }
    if(solve()){
        string ans;
        
        for(auto t:node){
            ans+=t;
            
        }
        ans+=ans[0];
        cout<<ans<<endl;
    }else{
        cout<<"No Solution"<<endl;
    }
}
/*
1
zA

4
aa
ab
bc
ca

4
aZ
tZ
Xt
aX
 */