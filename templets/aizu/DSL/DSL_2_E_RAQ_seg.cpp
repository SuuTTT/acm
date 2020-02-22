#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e5+5;
const int inf=(1ll<<31)-1;
#define lson (rt<<1)
#define rson (rt<<1|1)
int tag[maxn*4];
int data[maxn*4];//标记打成-1，用~-1==0简化代码
void upd(int rt,int l,int r,int x,int y,int v){
    if(x<=l&&r<=y)tag[rt]+=v;
    else{
        if(~tag[rt])tag[lson]=tag[rson]=tag[rt],tag[rt]=-1;
        int mid=(l+r)/2;
        if(y<=mid)upd(lson,l,mid,x,y,v);
        else if(x>mid) upd(rson,mid+1,r,x,y,v);
        else upd(lson,l,mid,x,mid,v),upd(rson,mid+1,r,mid+1,y,v);
    }
}
int find(int rt,int l,int r,int x){
    if(~tag[rt])return tag[rt];
    int mid=(l+r)>>1;
    if(x<=mid)return find(lson,l,mid,x);
    else return find(rson,mid+1,r,x);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
   // rep(i,1,(n<<2))tag[i]=inf;
    rep(i,1,q){
        int op,x,y,v;
        cin>>op;
        if(op){
            cin>>x>>y;
            cout<<find(1,1,n,x+1,y+1)<<endl;
        }else{
            int v;
            cin>>x>>y>>v;
            upd(1,1,n,x+1,y+1,v);
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
0≤s≤t<n
0≤x<231−1
 */