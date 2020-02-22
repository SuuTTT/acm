#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int fa[maxn];
int rk[maxn];
int sz[maxn];
int find(int x){
    return fa[x]==x? x:fa[x]=find(fa[x]);
}
void init(int n){rep(i,1,n)fa[i]=i,rk[i]=0;}
void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    fa[x]=y;
}
void uniteRk(int x,int y){
    int xx=find(x),yy=find(y);
    if(xx==yy)return;
    if(rk[xx]<rk[yy])fa[xx]=yy;
    else{
        fa[yy]=xx;
        if(rk[xx]==rk[yy])rk[xx]++;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    init(n);
    rep(i,1,q){
        int x,y,op;
        cin>>op>>x>>y;
        x++,y++;
        if(!op)uniteRk(x,y);
        else cout<<(find(x)==find(y))<<endl;
    }
}
/* 
5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
 */