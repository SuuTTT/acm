#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define debug(x) cerr<<#x<<": "<<x<<endl
const int inf=0x3f3f3f3f;
typedef long long ll;
const ll mod = (ll)1e9;
int n;
struct Rk{
    int rk,id;
    bool operator<(const Rk &x)const{
        return rk<x.rk;
    }
}r[100009];
ll t[100009];
ll a[400009];//线段树
int id[100009],cnt,siz[100009],rt;
struct Edge{
    int to,next;
}e[200009];
int head[100009],tot;
void add(int u,int v){
    tot++;
    e[tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
}
void dfs(int rt){
    id[rt]=++cnt;
    siz[rt]=1;
    for(int i=head[rt];i;i=e[i].next){
        dfs(e[i].to);
        siz[rt]+=siz[e[i].to];
    }
}
inline void build(int rt,int l,int r){
    if(l==r){
        a[rt]=0;
        return;
    }
    build(rt<<1,l,(l+r)>>1);
    build(rt<<1|1,((l+r)>>1)+1,r);
    a[rt]=a[rt<<1]+a[rt<<1|1];
}

inline ll query(int rt,int l,int r,int L,int R){
    if(L<=l&&r<=R)return a[rt];
    ll res=0;
    int mid=(l+r)>>1;
    if(L<=mid)res+=query(rt<<1,l,mid,L,R);
    if(R>mid)res+=query(rt<<1|1,mid+1,r,L,R);
    return res;
}

inline void update(int rt,int l,int r,int x,ll k){
    if(l==x&&r==x){
        a[rt]+=k;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid)update(rt<<1,l,mid,x,k);
    if(x>mid)update(rt<<1|1,mid+1,r,x,k);
    a[rt]=a[rt<<1]+a[rt<<1|1];
}
ll ans[100009];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int fa;
        scanf("%d%d%lld",&fa,&r[i].rk,&t[i]);
        r[i].id=i;
        if(fa==-1)rt=i;
        else add(fa,i);
    }
    dfs(rt);
    build(1,1,n);
    sort(r+1,r+1+n);
    for(int i=1;i<=n;i++){
        int now=r[i].id;
        ans[now]=query(1,1,n,id[now],id[now]+siz[now]-1);
        update(1,1,n,id[now],t[now]);
    }
    for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
    return 0;
}
/* 

 */