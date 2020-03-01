#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
struct node{
    int dis,a,b;
    bool operator<(const node &x)const{
        return dis>x.dis;
    }
    node(int dis=0,int a=0,int b=0):dis(dis),a(a),b(b){}
};
priority_queue<node>qu;
int n;
struct edge{
    int x,y;
    edge(int x=0,int y=0):x(x),y(y){}
}ans[2509];
int fa[2509];
int findfa(int u){
    if(u==fa[u])return fa[u];
    return fa[u]=findfa(fa[u]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        fa[i]=i;
        int x;
        for(int j=1;j<=n;j++){
            scanf("%d",&x);
            if(j>i)qu.push(node(x,i,j));
        }
    }
    int cnt=0;
    while(!qu.empty()){
        node now=qu.top();
        qu.pop();
        int faa=findfa(now.a),fab=findfa(now.b);
        if(faa==fab)continue;
        ans[cnt++]=edge(now.a,now.b);
        fa[faa]=fab;
    }
    for(int i=0;i<cnt;i++){
        printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}
/*

*/