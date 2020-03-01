#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;
#define debug(x) cerr<<#x<<":"<<x<<endl


const ll inf=1e8;
ll dis_is[505][505],dis_has[505][505];//1 连通，
map<string,ll> cla2int;
ll n,q,tot;
string a[10005],b[10005],connect[10005],x,u,y;

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n>>q){
        cla2int.clear();
        tot=0;
        rep(i,1,n)cin>>a[i]>>connect[i]>>b[i];
        rep(i,1,n){
            if(cla2int.find(a[i])==cla2int.end())cla2int[a[i]]=++tot;
            if(cla2int.find(b[i])==cla2int.end())cla2int[b[i]]=++tot;
        }
        rep(i,1,tot)rep(j,1,tot)dis_is[i][j]=(i==j?0:inf);
        rep(i,1,tot)rep(j,1,tot)dis_has[i][j]=inf;
        rep(i,1,n){
            if(connect[i]=="is-a"){
                dis_is[cla2int[a[i]]][cla2int[b[i]]]=0;
            }else{
                dis_has[cla2int[a[i]]][cla2int[b[i]]]=1;
            }
        }
         rep(k,1,tot)rep(i,1,tot)rep(j,1,tot){
            dis_is[i][j]=min(dis_is[i][j],dis_is[i][k]+dis_is[k][j]);
        }
        rep(k,1,tot)rep(i,1,tot)rep(j,1,tot){
            dis_has[i][j]=min(dis_has[i][j],dis_has[i][k]+dis_has[k][j]);
            dis_has[i][j]=min(dis_has[i][j],dis_has[i][k]+dis_is[k][j]);
            dis_has[i][j]=min(dis_has[i][j],dis_is[i][k]+dis_has[k][j]);
        }
       
        
        rep(it,1,q){
            cin>>x>>u>>y;
            cout<<"Query "<<it<<": ";
            if(u=="is-a")cout<<(dis_is[cla2int[x]][cla2int[y]]==0?"true":"false")<<endl;
            else cout<<(dis_has[cla2int[x]][cla2int[y]]>0&&dis_has[cla2int[x]][cla2int[y]]!=inf ?"true":"false")<<endl;
        }
    }
    return 0;
}
/*
4 1
a has-a b
b has-a c
a is-a d
d is-a c
a has-a c
*///
