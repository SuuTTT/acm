/* 
time: MlogM

 */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
struct edge{
    int x,y,w;
    edge(int x=0, int y=0, int w=0):x(x),y(y),w(w){};
}e[maxn]];
int getfather(int x){
    if(x==fa[x])return x;
    else return fa[x]=getfather(fa[x]);
}
int kruscal(){
    sort(e+1,e+M+1,cmp);//边权小到大
    int cnt=N;
    rep(i,1,N)fa[i]=i;
    rep(i,1,M){
        int t1=getfather(e[i].x);
        int t2=getfather(e[i].y);
        if(t1!=t2){
            fa[t1]=t2;
            ans+=e[i].w;
            if(cnt==1)break;
        }
    }
    return ans;
}
int main(){
ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}