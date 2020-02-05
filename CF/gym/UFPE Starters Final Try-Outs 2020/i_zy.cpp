#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int father[maxn],rk[maxn],sz[maxn];
void init(int n){
    for(int i=0;i<n;i++)father[i]=i,sz[i]=1;
}
int find(int v){
    return father[v]=father[v]==v?
    v:find(father[v]);
}

void merge(int x,int y){
    int a=find(x),b=find(y);
    if(a==b)return;
    if(rk[a]<rk[b]){
        father[a]=b;
        sz[b]+=sz[a];
    }else{
        father[b]=a;
        sz[a]+=sz[b];
        if(rk[b]==rk[a]){
            ++rk[a];
        }
    }
}
//confused with vis, it's useless. Because the deeper one must have been visited, vice versa
struct S{
    int x,y,dep;
    operator < (const S& r) const{
        return dep>r.dep;
    }
};


vector<int> ve[maxn];
vector<S> V;
int dir[4][2]={-1,0, 0,1, 1,0, 0,-1};
int s,n,m;
int id(int x,int y){
    return (x-1)*(m)+y-1;
}
int main(){
    
    cin>>s>>n>>m;
    rep(j,0,m+1)ve[0].push_back(0),ve[n+1].push_back(0);
    rep(i,1,n){
        ve[i].push_back(0);
        rep(j,1,m){
            int x;
            scanf("%d",&x);
            ve[i].push_back(x);
            V.push_back({i,j,x});
        }
        ve[i].push_back(0);
    }
    sort(V.begin(),V.end());
    init(n*m);
    rep(i,0,V.size()-1){
        rep(j,0,3){
            int dx=V[i].x+dir[j][0];
            int dy=V[i].y+dir[j][1];
            if(ve[dx][dy]>=V[i].dep){
                merge(id(dx,dy),id(V[i].x,V[i].y));
               // debug(i),debug(dx),debug(dy);
            }
        }
        if(sz[find(id(V[i].x,V[i].y))]>=s){
            cout<<V[i].dep<<endl;
            break;
        }
    }

}
/*
3 2 4
9 7 7 9
7 8 8 7
*/