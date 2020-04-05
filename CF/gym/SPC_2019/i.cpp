#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>

using namespace std;
#define int long long
const int inf=(int)1e18;
inline int read()
{
  int x=0,f=1;char ch=getchar();
  while (!isdigit(ch)) {if (ch=='-') f=-1;ch=getchar();}
  while (isdigit(ch)) {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
  return x*f;
}

const int maxn = 100010;

struct Node{
    int d,first;
};

Node f[4*maxn];
Node add[4*maxn];
int a[4*maxn];
int n,m;

void pushdown(int root,int l,int r)
{
    if (f[root].d || f[root].first)
    {
        int mid = (l+r) >> 1;
        f[2*root].d+=f[root].d;
        f[2*root+1].d+=f[root].d;
        f[2*root].first+=f[root].first;
        f[2*root+1].first+=(f[root].first+(mid-l+1)*f[root].d);
        f[root].d=f[root].first=0;
    }
}

void update(int root,int l,int r,int x,int y,int first,int d)
{
    if (x<=l && r<=y){
        f[root].d+=d;
        f[root].first+=(l-x)*d+first;
        return ;
    }
    pushdown(root,l,r);
    int mid = (l+r) >> 1;
    if (x<=mid) update(2*root,l,mid,x,y,first,d);
    if (y>mid) update(2*root+1,mid+1,r,x,y,first,d);
}
/* int query(int root,int l,int r,int x,int y){
    if (x<=l && r<=y){
        return f[root].d==0?f[root].first:inf;
    }
    pushdown(root,l,r);
    int mid = (l+r) >> 1;
    int ll=query(2*root,l,mid,x,y),rr=query(2*root+1,mid+1,r,x,y);
    if(ll==inf||rr==inf)return inf;
    if(ll==rr)return ll;
    
} */
int query(int root,int l,int r,int x,int y)
{
    if (l==r)
    {
      return a[l]+f[root].first;
    }
    pushdown(root,l,r);
    int mid = (l+r) >> 1;
    if (pos<=mid)  return query(2*root,l,mid,pos);
    if (pos>mid) return query(2*root+1,mid+1,r,pos);
}

signed main()
{   
  scanf("%d%d",&n,&m);
  //for (int i=1;i<=n;i++) a[i]=read();
  for (int i=1;i<=n;i++){
      a[i]=read();
       update(1,1,n,1,1,a[i],0);
  } 
  for (int i=1;i<=m;i++)
  {
    int opt;
    opt=read();
    if (opt==2)
    {
        int l,r,k,d;
        l=read(),r=read(),k=read(),d=read();
        update(1,1,n,l,r,k,d);
      }
    else
    {
        int l=read(),r=read();
        printf("%d\n",query(1,1,n,l,r)!=inf);
    }
  }
  return 0;
}


/* 
\
区间加 等差数列
区间询问是否一样<=> 询问区间的d是否是0&&区间的首项相等
5 3
2 1 3 4 1
1 1 3
1 4 5

 */