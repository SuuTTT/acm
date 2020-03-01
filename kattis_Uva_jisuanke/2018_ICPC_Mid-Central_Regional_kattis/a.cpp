#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

typedef double db;
const db eps=1e-7;
struct Point{
    db x,y;
    Point(){}
    Point(db x,db y):x(x),y(y){}
    Point operator + (const Point &b)const{return Point(x+b.x,y+b.y);}
    Point operator - (const Point &b)const{return Point(x-b.x,y-b.y);}
    Point operator * (db b)const{return Point(x*b,y*b);}
    Point operator / (db b)const{return Point(x/b,y/b);}
    bool operator == (const Point &b)const{return fabs(x-b.x)<eps && fabs(y-b.y)<eps;}
    db operator * (const Point &b)const{return x*b.x+y*b.y;}
    db operator / (const Point &b)const{return x*b.y-y*b.x;}
    db length()const{return sqrt(x*x+y*y);}
};
template<ll n> class uset{
public:
    ll Set[n+1];
    void init(){
        rep(i,0,n)Set[i]=i;
    }
    ll find(ll x){
        if(Set[x]!=x)Set[x]=find(Set[x]);
        return Set[x];
    }
    void unionset(ll x,ll y){
        Set[y]=x;
    }
};
template<ll maxn,ll maxm,typename E> class Graph{
public:
    ll head[maxn],tot;
    E edge[maxm];
    void init(){
        tot=0;
        memset(head,-1,sizeof(head));
    }
    void add(E e){
        edge[tot]=e;
        edge[tot].next=head[e.u];
        head[e.u]=tot++;
    }
    static bool kruskal_cmp(E e1,E e2){return e1.w<e2.w;}
    double kruskal(ll n){
        static E e[maxm];
        static uset<maxn> se;
        se.init();
        rep(i,0,tot-1)e[i]=edge[i];
        sort(e,e+tot,kruskal_cmp);
        double ans=0;
        rep(i,0,tot-1){
            ll r1=se.find(e[i].u),r2=se.find(e[i].v);
            if(r1!=r2){
                se.unionset(r1,r2);
                n--;
                ans+=e[i].w;
            }
        }
        return ans;
    }
};
struct Edge{
    ll u,v,next;
    double w;
}E;

Point P[1005];
ll n,e,p;
Graph<1005,1000005,Edge> G;
double dis[1005][1005];

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n>>e>>p){
        rep(i,1,n)cin>>P[i].x>>P[i].y;
        rep(i,1,n)rep(j,1,n)dis[i][j]=(P[i]-P[j]).length();
        rep(i,1,e)rep(j,1,e)dis[i][j]=0;
        while(p--){
            ll u,v;
            cin>>u>>v;
            dis[u][v]=dis[v][u]=0;
        }
        G.init();
        rep(i,1,n)rep(j,1,n)if(i!=j){
            E.u=i,E.v=j,E.w=dis[i][j];
            G.add(E);
        }
        cout<<fixed<<setprecision(6)<<G.kruskal(n)<<endl;
    }
    return 0;
}
/*

*///