#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
/*
vis[v]: 1 is in stack. 0 is unvisited, 2 is visited.
dfn[v]: the depth of v( when it is visited).
low[v]: the earliest visited ancestor that available to v
*/
const int V=1000;
int edge[V][V];//邻接矩阵
int bridge[V][V],cut[V];//bridge[i,j]是否是桥,cut[i]是否是割点
int low[V],dfn[V],vis[V];
//dep:cur节点被访问时的深度. n:图的总点数。
void cut_bridge(int cur,int father,int dep,int n){//node 0~n-1
    vis[cur]=1;dnf[cur]=low[cur]=dep;
    int children=0;
    for(int i=0;i<n;i++)if(edge[cur][i]){
        if(i!=father && 1==vis[i]){
            //i在栈中，说明图中有一个环，用i的深度更新low值
            if(dfn[i]<low[cur])
                low[cur]=dfn[i];
        }
        if(0==vis[i]){
            //i没被访问过，递归访问i
            cut_bridge(i,cur,dep+1,n);
            children++;
             //并用i可以到达的最早祖先来更新low[cur]
            if(low[i]<low[cur])low[cur]=low[i];
            //cur是割点的条件：cur是根且有大于一个儿子，
            //或cur不是根，且cur有一个儿子v使得low[v]>=dfn[cur]
            if( (father==-1 && children>1)||
            (father!=-1&&low[i]>=dfn[cur]) ) cut[cur]=1;
            //(cur,i)是桥的条件：low[i]>dnf[cur]
            if(low[i]>dfn[cur])bridge[cur][i]=bridge[i][cur]=1;
        }
        vis[cur]=2;
    }

}