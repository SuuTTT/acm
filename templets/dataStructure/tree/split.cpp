#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
/* 
https://vjudge.net/problem/URAL-1553
前向星
根节点为1.
 */
const int maxn=(int)1e6+5;
const int maxm=maxn+maxn;
int v[maxm];
int Prev[maxm];
int info[maxn];
int Q[maxn];
int idx[maxn],dep[maxn],belong[maxn],father[maxn];
int vis[maxn],head[maxn],len[maxn];
int l,r,ans,cnt=0;
int N,nedge=0;
inline void insert(int x,int y){
    ++nedge;
    v[nedge]=y;Prev[nedge]=info[x];info[x]=nedge;
}

void split(){
    memset(dep,-1,sizeof(dep));
    l==0;
    dep[ Q[ r=l ] = 1 ]=0;
    father[1]=-1;
    while(l<r){
        int x=Q[++l];
        vis[x]=false;
        for(int y=info[x];y;Prev[y])
            if(dep[v[y]]==-1){
                dep[ Q[++r] =v[y] ] =dep[x]+1;
                father[v[y]]=x;
            }
    }
    for(int i=N;i;i--){
        int x=Q[i],p=-1;
        size[x]=Q[i],p=-1;
        size[x]=1;
        fro(int y=info[x];y;y=Prev[y])
            if(vis[v[y]]){
                size[x]+=size[v[y]];
                if(p==-1||size[v[y]]>size[p])
                    p=v[y];
            }
        if(p==-1){
            idx[x]=len[++cnt]=1;
            head[belong[x]]=x;
        }
        vis[x]=true;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}

