#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
/* index_0 */
vector<int> f;//father, f[root]=-sz; 
vector<int> d;//depth or dif, d[x]=x.val-f[x].val;
int sz[maxn];
int find(int x){
    if(f[x]<0)return x;
    int tmp=find(f[x]);
    d[x]+=d[f[x]];
    return f[x]=tmp;
}
void init(int n=1){f.clear();f.resize(n,-1);d.clear(),d.resize(n,0);}
int dept(int x){find(x);return d[x];}
void unite(int x,int y,int z=0){//y-x=z
    z+=dept(x)-dept(y);//critical
    x=find(x),y=find(y);
    if(x==y)return;
    if(f[x]<f[y])swap(x,y),z*=-1;
    f[x]+=f[y];
    f[y]=x;
    d[y]=z;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    init(n);
    rep(i,1,q){
        int op,x,y,z;
        scanf("%d",&op);
        if(op){
            scanf("%d%d",&x,&y);
            if(find(x)!=find(y))cout<<'?'<<endl;
            else cout<<d[y]-d[x]<<endl;
        }else{
            scanf("%d%d%d",&x,&y,&z);
            unite(x,y,z);
        }
    }
}
/*
DSL_1_B
4 3
0 1 2 1
0 2 3 1
1 1 3


5 6
0 0 2 5
0 1 2 3
1 0 1
1 1 3
0 1 4 8
1 0 4

*/
