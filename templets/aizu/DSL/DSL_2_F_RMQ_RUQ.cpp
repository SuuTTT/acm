#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
const int inf=(1ll<<31)-1;
int data[maxn*4];
#define lson (rt<<1)
#define rson (rt<<1|1)

/* 
左开右闭
 */
void upd(int rt,int l,int r,int x,int y,int v){
    if(y<=l||x>=r)return;
    if(x<=l&&y>=r)data[rt]=v;
    else{
        if(~data[rt]){
            upd(lson,l,l+r>>1,l,r,data[rt]);
            upd(rson,l+r>>1,r,l,r,data[rt]);
            data[rt]=-1;
        }
        upd(lson,l,l+r>>1,x,y,v);
        upd(rson,l+r>>1,r,x,y,v);
    }
}
int query(int rt,int l,int r,int x,int y){
    if(y<=l||x>=r)return inf;
    if(~data[rt])return data[rt];
    else return min(query(lson,l,l+r>>1,x,y),query(rson,l+r>>1,r,x,y));
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    rep(i,1,n)data[i]=inf;
    rep(i,1,q){
        int op,x,y,v;
        cin>>op;
        if(op){
            cin>>x>>y;
            cout<<query(1,1,n+1,x+1,y+2)<<endl;
        }else{
            int v;
            cin>>x>>y>>v;
            upd(1,1,n+1,x+1,y+2,v);
        }
    }
}
/* 
3 5
0 0 1 1
0 1 2 3
0 2 2 2
1 0 2
1 1 2

1≤n≤100000
1≤q≤100000
1≤s≤t≤n
0≤x<1000
 */