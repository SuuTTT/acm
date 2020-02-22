#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
const int inf=(1ll<<31)-1;
/* O(Qsqrt(N)) */
int a[maxn],belong[maxn],bsize;
int fst[maxn],lst[maxn],rmin[maxn];
void init (int n){
    bsize=sqrt(n);
    rep(i,1,n)a[i]=inf;
    rep(i,1,bsize)fst[i]=(1-i)*bsize+1,lst[i]=i*bsize;
    if(lst[bsize]<n)bsize++,fst[bsize]=lst[bsize-1]+1,lst[bsize]=n;//bsize变为bnum
    rep(i,1,bsize){
        rep(j,fst[i],lst[i])belong[j]=i,rmin[i]=min(rmin[i],a[j]);
    }
}
int query(int l,int r){
    int ret=inf;
    if(belong[l]==belong[r]){
        rep(i,l,r)ret=min(ret,a[i]);
        return ret;
    }
    rep(i,l,lst[belong[l]])ret=min(ret,a[i]);
    rep(i,belong[l]+1,belong[r]-1)ret=min(ret,rmin[i]);
    rep(i,fst[belong[r]],r)ret=min(ret,a[i]);
    return ret;
}
void update(int x,int v){
    a[x]=v;
    rmin[belong[x]]=inf;
    rep(i,fst[belong[x]],lst[belong[x]]){
        rmin[belong[x]]=min(rmin[belong[x]],a[i]);
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    init(n);
    rep(i,1,q){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==0)update(y+1,z);
        else cout<<query(y+1,z+1)<<endl;
    }
}
/* 
3 5
0 0 1
0 1 2
0 2 3
1 0 2
1 1 2
 */