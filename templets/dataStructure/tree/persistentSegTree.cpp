#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e5+5;

struct node{
    int l,r,s;
}tree[maxn*24];
int cnt,n,m,q;
int a[maxn],b[maxn],t[maxn];
int build(int l,int r){
    int rt=cnt++;
    int mid=l+r>>1;
    if(l>=r)return rt;
    tree[rt].l=build(l,mid);
    tree[rt].r=build(mid+1,r);
    return rt;
}
void update(int &cur,int pre,int l,int r,int x){
    tree[++cnt]=tree[pre];
    tree[cnt].s++;
    cur=cnt;
    if(l>=r)return ;
    int mid=l+r>>1;
    if(x<=mid)update(tree[cur].l,tree[pre].l,l,mid,x);
    else update(tree[cur].r,tree[pre].r,mid+1,r,x);

}
int query(int u,int v,int l,int r,int k){//维护下标在(u,v]内元素的权值线段树中查找第k大。
    if(l>=r)return l;
    int x=tree[tree[v].l].s-tree[tree[u].l].s;//值域在[l,mid]内的元素个数x,
    int mid=l+r>>1;
    if(x>=k)query(tree[u].l,tree[v].l,l,mid,k);
    else query(tree[u].r,tree[v].r,mid+1,r,k-x);

}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tt;cin>>tt;
    while(tt--){
        scanf("%d%d",&n,&q);
        rep(i,1,n){scanf("%d",&a[i]);b[i]=a[i];}
        sort(b+1,b+1+n);
        m=unique(b+1,b+1+n)-b-1;
        //debug(m);
        t[0]=build(1,m);
        rep(i,1,n){
            int l=lower_bound(b+1,b+1+m,a[i])-b;
            update(t[i],t[i-1],1,m,l);
        }
        rep(i,1,q){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            //cin>>x>>y>>k;
            cout<<b[query(t[x-1],t[y],1,m,k)]<<endl;
        }
    }
    
}
/* 
//SHORTER && FASTER version
int N, M, tot, root[MAXN], A[MAXN], l, r, k;
struct Node { int lson, rson, sum; }T[MAXN * 25];
vector<int> vp;
int getID(int x) { return lower_bound(vp.begin(), vp.end(), x) - vp.begin() + 1; };

void Update(int l, int r, int &cur, int last, int pos) {
    T[++tot] = T[last], T[tot].sum++, cur = tot;
    if (l == r)return;
    int mid = l + r >> 1;
    if (mid >= pos) Update(l, mid, T[cur].lson, T[last].lson, pos);
    else            Update(mid + 1, r, T[cur].rson, T[last].rson, pos);
}

int Query(int l, int r, int last, int cur, int k) {
    if (l == r) return l;
    int mid = l + r >> 1;
    int sum = T[T[cur].lson].sum - T[T[last].lson].sum;
    if (sum >= k) return Query(l, mid, T[last].lson, T[cur].lson, k);
    else          return Query(mid + 1, r, T[last].rson, T[cur].rson, k - sum);
}
void init() {
    vp.clear(); tot = 0;
}
int main()
{
    int t; cin >> t; while (t--) {
        scanf("%d %d", &N, &M);
        init();
        rep(i, 1, N) scanf("%d", &A[i]), vp.pb(A[i]);
        sort(vp.begin(), vp.end()), vp.erase(unique(vp.begin(), vp.end()), vp.end());
        rep(i, 1, N) Update(1, N, root[i], root[i - 1], getID(A[i]));
        rep(i, 1, M) {
            scanf("%d %d %d", &l, &r, &k);
            printf("%d\n", vp[Query(1, N, root[l - 1], root[r], k) - 1]);
        }
    }

}
 */