#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

class People{
public:
    set<string> lang;
    string speak;
    bool can_understand(string s){
        return lang.find(s)!=lang.end();
    }
};
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

Graph G;
People P[105];
ll n;

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    string s,temp;
    getline(cin,s);
    rep(i,1,n){
        getline(cin,s);
        stringstream ss(s);
        ss>>temp;
        ss>>temp;
        P[i].speak=temp;
        P[i].lang.insert(temp);
        while(ss>>temp)P[i].lang.insert(temp);
    }
    G.resize(n);
    rep(i,1,n)rep(j,1,n)if(i!=j and P[j].can_understand(P[i].speak))G.add_edge(i,j);
    G.find_scc();
    cout<<n-G.find_max_scc()<<endl;
    return 0;
}

/* 
100个人
每个人会说一种语言，听得懂若干语言。
问最少去掉几个人可以使得所有人互相交流（可以通过别人翻译）。
 */