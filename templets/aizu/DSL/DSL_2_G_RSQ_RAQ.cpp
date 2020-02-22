#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int uni[maxn*4],part[maxn*4];
#define lson (rt<<1)
#define rson (rt<<1|1)

/* 
左闭右开，index——1
 */
void add(int rt,int l,int r,int x,int y,int v){
    if(y<=l||x>=r)return;
    if(x<=l&&y>=r)uni[rt]+=v;
    else{
        part[rt]+=(min(r,y)-max(x,l))*v;
        add(lson,l,l+r>>1,x,y,v);
        add(rson,l+r>>1,r,x,y,v);
    }
}
int sum(int rt,int l,int r,int x,int y){
    if(y<=l||x>=r)return 0;
    if(x<=l&&y>=r)return (r-l)*uni[rt]+part[rt];
    int ret=(min(r,y)-max(x,l))*uni[rt];
    ret+=sum(lson,l,l+r>>1,x,y);
    ret+=sum(rson,l+r>>1,r,x,y);
    return ret;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
   // int N=1;
    //while(N<n)N*=2;n=N;
    rep(i,1,q){
        int op,x,y,v;
        cin>>op;
        if(op){
            cin>>x>>y;
            cout<<sum(1,1,n+1,x,y+1)<<endl;
        }else{
            int v;
            cin>>x>>y>>v;
            add(1,1,n+1,x,y+1,v);
        }
    }
}
/* 
3 5
0 1 2 1
0 2 3 2
0 3 3 3
1 1 2
1 2 3

1≤n≤100000
1≤q≤100000
1≤s≤t≤n
0≤x<1000
 */