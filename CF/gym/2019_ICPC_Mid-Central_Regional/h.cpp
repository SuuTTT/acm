#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int N=500001;
int n,q,m,cnt;
int a[N],b[N],t[N];
struct TREE
{
    int s,l,r;
}tre[N<<5];
int build(int l,int r)
{
    int p=++cnt;
    if(l<r)
    {
        int mid=(l+r)>>1;
        tre[p].l=build(l,mid);
        tre[p].r=build(mid+1,r);
    }
    return p;
}
int update(int p1,int l,int r,int x)
{
    int p=++cnt;
    tre[p].l=tre[p1].l;
    tre[p].r=tre[p1].r;
    tre[p].s=tre[p1].s+1;
    if(l<r)
    {
        int mid=(l+r)>>1;
        if(x<=mid)tre[p].l=update(tre[p1].l,l,mid,x);
		else tre[p].r=update(tre[p1].r,mid+1,r,x);
    }
    return p;
}
int query(int u,int v,int l,int r,int k)
{
    if(l>=r)return 1;
    int lnum=tre[tre[v].l].s-tre[tre[u].l].s;
	int rnum=tre[tre[v].r].s-tre[tre[u].r].s;
    int mid=(l+r)>>1;
    if(lnum>k)return query(tre[u].l,tre[v].l,l,mid,k);
    if(rnum>k)return query(tre[u].r,tre[v].r,mid+1,r,k);
    return 0;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
		double tmp;
        scanf("%lf",&tmp);
        b[i]=a[i]=tmp*1000000;
    }
    sort(b+1,b+n+1);
    m=unique(b+1,b+n+1)-b-1;
    t[0]=build(1,m);
    for(int i=1;i<=n;i++)
    {
        int l=lower_bound(b+1,b+m+1,a[i])-b;
        t[i]=update(t[i-1],1,m,l);
    }
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf(query(t[l-1],t[r],1,m,(r-l+1)/2)?"usable\n":"unusable\n");
    }
}
/* 
8 4
7.000000
8.314634
7.000001
7.000000
2.581236
7.000000
2.581236
7.000000
1 8
1 3
4 8
5 7
 */