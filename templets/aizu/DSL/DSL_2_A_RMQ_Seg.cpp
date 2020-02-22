#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e5+5;
const int inf=(1ll<<31)-1;
#define lson (rt<<1)
#define rson (rt<<1|1)
int mini[maxn*4];
void upd(int rt,int l,int r,int loc,int v){
    if(l==r)mini[rt]=v;
    else{
        int mid=(l+r)/2;
        if(loc<=mid)upd(lson,l,mid,loc,v);
        else upd(rson,mid+1,r,loc,v);
        mini[rt]=min(mini[lson],mini[rson]);
    }
}
int find(int rt,int l,int r,int x,int y){
    if(x<=l&&r<=y)return mini[rt];
    int mid=(l+r)>>1;
    if(y<=mid)return find(lson,l,mid,x,y);
    if(x>mid)return find(rson,mid+1,r,x,y);
    else{
        return min(find(lson,l,mid,x,mid),
        find(rson,mid+1,r,mid+1,y));
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    rep(i,0,(n<<2))mini[i]=inf;
    rep(i,1,q){
        int op,x,y;
        cin>>op>>x>>y;
        if(op)cout<<find(1,1,n,x+1,y+1)<<endl;
        else upd(1,1,n,x+1,y);
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