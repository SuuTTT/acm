#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
//有向图中将极大强连通分量染色，
struct strongly_connected_components{
    vector<int> &color;
    vector<int> Stack;
    int colorCnt, curr, *instack, *dfn, *low, *info, *next, *to;

    void dfs(int x){
        //dfs遍历，一路上标记dfn并把新节点压入栈。
        dfn[x]=low[x]=++curr;
        Stack.push_bakc(x);
        instack[x]=true;
        //求low值
        for(int j=info[x];j;j=next[j])
            //如果i访问到新的j，j的low值i一定能达到，用low[j] update low[i]
            if(!instack[to[j]]){
                dfs(to[j]);
                low[x]=min(low[x],low[to[j]]);
            //如果i访问到最先k，直接用dfn[k]更新low[i]
            } else{
                if(instack[to[j]]==1)
                    low[x]=min(low[x],dfn[to[j]]);
            }
        //对于一个节点，如果low 与dfn相等，说明它无法到达祖先
        //而在栈里面i与i之后的点一定是可以互达的，形成极大强连通
        if(low[x]==dfn[x]){
            while(Stack.back()!=x){
                color[Stack.back()]=colorCnt;
                instack[Stack.back()]=2;
                Stack.pop_back();
            }
            color[Stack.back()]=colorCnt++;
            instack[Stack.back()]=2;
            Stack.pop_back();
        }
    }

    strongly_connected_components(const vector<pair<int,int> >&edgeList,
     int n, vector<int>&ans):color(ans){
         color.resize(n);
        instack = new int[n];
        dfn = new int[n];
        low = new int[n];
        info = new int[n];
        next = new int[(int)edgeList.size()+5];
        to = new int[(int)edgeList.size()+5];
        fill_n(info,n,0);
        for(size_t i=0;i<edgeList.size();i++){
            to[i+1]=edgeList[i].second;
            vext[i+1]=info[edgeList[i].first];
            info[edgeList[i].first]=i+1;
        }

        fill_n(instack,n,0);
        colorCnt=0;
        curr=0;
        for(int i=0;i<n;i++){
            if(!instack[i]){
                dfs(i);
            }
        }
        delete[] instack;
        delete[] dfn;
        delete[] low;
        delete[] info;
        delete[] next;
        delete[] to;
     } 
};
int main(){}
/* 
class Graph{
public:
    int n;
    vector< vector<int> > to;
    vector<int> dfn,low,stk,scc,num;
    int sccnum,index;
    void resize(int n_){
        n=n_;
        to.resize(n+1);
    }
    void add_edge(int u,int v){
        to[u].emplace_back(v);
    }
    void tarjan(int root){
        dfn[root]=low[root]=++index;
        stk.emplace_back(root);
        for(auto v:to[root]){
            if(!dfn[v]){
                tarjan(v);
                low[root]=min(low[root],low[v]);
            }else if(!scc[v]){
                low[root]=min(low[root],low[v]);
            }
        }
        if(low[root]==dfn[root]){
            sccnum++;
            while(1){
                int x=stk.back();
                scc[x]=sccnum;
                stk.pop_back();
                if(x==root)break;
            }
        }
    }
    void find_scc(){
        dfn.resize(n+1);
        low.resize(n+1);
        scc.resize(n+1);
        sccnum=index=0;
        rep(i,1,n)if(!dfn[i])tarjan(i);
    }
    ll find_max_scc(){
        num.resize(sccnum+1);
        rep(i,1,n)num[scc[i]]++;
        return *max_element(num.begin(),num.end());
    }
};

 */