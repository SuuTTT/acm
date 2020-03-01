#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e5+5;
const int inf=2000000000;
/* GRL_1_A 
index_0
directed edge
There are no parallel edges
There are no self-loops

*/
struct Info{//相当于存的是边及其后端点
    int to,cost;
    Info(int _to,int _cost){
        to=_to,cost=_cost;
    }
    bool operator< (const Info& arg) const {
        return cost>arg.cost;
    }
};
vector <Info> Edges[maxn];
int d[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int V,E,st;
    cin>>V>>E>>st;
    fill(d+0,d+V,inf);
    rep(i,1,E){
        int s,t,d0;
        cin>>s>>t>>d0;
        Edges[s].push_back(Info(t,d0));
    }
    priority_queue<Info> Q;
    d[st]=0;
    Q.push(Info(st,d[st]));
    while(!Q.empty()){
        Info now=Q.top();
        Q.pop();
        for(auto v:Edges[now.to]){
            if(d[v.to]>d[now.to]+v.cost){
                d[v.to]=d[now.to]+v.cost;
                Q.push(Info(v.to,d[v.to]));
            }
        }
        
    }
    rep(i,0,V-1){
        if(d[i]==inf)cout<<"INF\n";
        else cout<<d[i]<<endl;
    }
}
/* 
4 6 1
0 1 1
0 2 4
2 0 1
1 2 2
3 1 1
3 2 5

1 ≤ |V| ≤ 1000
0 ≤ |E| ≤ 2000
-10000 ≤ di ≤ 10000


|V| |E| r
s0 t0 d0
s1 t1 d1
:
s|E|−1 t|E|−1 d|E|−1
 */