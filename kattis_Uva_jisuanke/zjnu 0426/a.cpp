#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e7+5;
typedef pair<int,int> pii;
#define flr first
#define tim second
int vis[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    queue<pii> Q;
    Q.push({s,0});
    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();
        if(cur.flr==g){
            cout<<cur.tim<<endl;
            return 0;
        }
        if(cur.flr+u<=f&&!vis[cur.flr+u]){
            Q.push({cur.flr+u,cur.tim+1});
            vis[cur.flr+u]=1;
        }
        int curf=cur.flr-d;
        if(curf>=1&&!vis[curf]){
            Q.push({curf,cur.tim+1});
            vis[curf]=1;
        }
    }
    cout<<"use the stairs"<<endl;
}