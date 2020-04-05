#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int father[maxn];
void init(int n){
    for(int i=0;i<n;i++)father[i]=i;
}
int find(int v){
    return father[v]=father[v]==v?
    v:find(father[v]);
}
void un(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    father[x]=y;
}
map<long long,int> mp,mpx;
int cnt,cntx;
int id(int x,int y,int z){
    long long tmp=x*100000000+y*10000+z;
    if(mp.count(tmp))return mp[tmp];
    else return mp[tmp]=++cnt;
}
int idx(int y,int z){
    long long tmp=y*10000+z;
    if(mpx.count(tmp))return mpx[tmp];
    else return mpx[tmp]=++cntx;
}

int X[maxn][2],Y[maxn][2];
//bool vis[50005][50005];
map<int ,int> vis[maxn];
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k;
    cin>>k;debug(k);
    int n=k;
    rep(i,1,k){
        int z,x,c,a,s,d;
        scanf("%d%d%d%d%d%d",&z,&x,&c,&a,&s,&d);
        int xx=id(z,x,c),yy=id(a,s,d);
        X[i][0]=xx,Y[i][0]=yy;
        /* E[xx].push_back(yy);
        E[yy].push_back(xx); */
        xx=idx(z,x),yy=idx(a,s);
         X[i][1]=xx,Y[i][1]=yy;
        /* EX[xx].push_back(yy);
        EX[yy].push_back(xx); */
    }
    init(2*k);
    int flag=0;
    rep(i,1,n){
        //debug(X[i][0]),debug(Y[i][0]);
        if(find(X[i][0])==find(Y[i][0])){flag=1;break;}
        un(X[i][0],Y[i][0]);
    }
    puts(flag?"True closed chains":"No true closed chains");
    init(2*k);
    flag=0;
    rep(i,1,n){
        if(X[i][1]==Y[i][1])continue;//point
        if(vis[X[i][1]][Y[i][1]])continue;//edge
        vis[X[i][1]][Y[i][1]]=1;
        vis[Y[i][1]][X[i][1]]=1;
        if(find(X[i][1])==find(Y[i][1])){flag=1;break;}
        un(X[i][1],Y[i][1]);
    }
    puts(flag?"Floor closed chains":"No floor closed chains");
}
/* 
给50000条三维线段，问是否存在3D的环以及xoy平面上投影是否存在环
4
12 12 8 10 5 11
12 12 8 4 14 21
12 12 8 12 20 8
4 14 21 10 5 21

3
50 50 50 100 100 100
100 100 100 50 50 90
50 50 90 50 50 50
问题：题意理解问题？
3
1 1 1 1 1 2
1 1 2 1 1 3
1 1 3 1 1 1

3
1 1 1 1 1 2 
1 1 2 2 2 2
2 2 2 1 1 1
1.id
2.
 */