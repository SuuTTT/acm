#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define debug(x) cerr<<#x<<": "<<x<<endl
const int inf=0x3f3f3f3f;
typedef long long ll;
const ll mod = (ll)1e9;
struct node{
    int w,id;
    bool operator<(const node &a)const{
        return w<a.w;
    }
}x[1000009];
int a[1000009];
int n,m;
int fa[1000009];
int d[1000009];
vector<int>has[1000009];
map<int,int>mp;
int cnt;
int findfa(int u){
    if(u==fa[u])return fa[u];
    return fa[u]=findfa(fa[u]);
}
void uv(int u,int v){
    int fau=findfa(u),fav=findfa(v);
    if(fau==fav)return;
    if(d[fau]>d[fav])swap(fau,fav);
    fa[fau]=fav;
}
int getd(int u){
    if(u==fa[u])return d[u];
    return d[u]=getd(fa[u]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        fa[i]=i;
        scanf("%d",&x[i].w);
        x[i].id=i;
    }
    sort(x+1,x+1+n);
    for(int i=1;i<=n;i++){
        if(mp[x[i].w]==0)mp[x[i].w]=++cnt;
        a[x[i].id]=mp[x[i].w];
    }
    for(int i=1;i<=n;i++){
        d[i]=a[i];
        has[a[i]].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=cnt;i++){
        int res=0;
        for(int j=0;j<has[i].size();j++){
            int p=has[i][j];
            res++;
            if(p>1&&getd(p-1)<=getd(p)){
                if(getd(p-1)==getd(p)&&findfa(p-1)!=findfa(p))res--;
                uv(p-1,p);
            }
            if(p<n&&getd(p+1)<=getd(p)){
                if(getd(p+1)==getd(p)&&findfa(p+1)!=findfa(p))res--;
                uv(p+1,p);
            }
        }
        ans=max(ans,res);
    }
    if(ans>has[1].size())ans=-1;
    printf("%d\n",ans);
    return 0;
}
/*
11 4
4 1 3 4 2 1 1 2 3 4 2
*/

/* 
K: n个数初始都是0，每年都会+1。每年Ayoub都可以选择刚好k个不相交区间的数变为0（也可以一个都不选）。给出m年后每个数的大小，求k的最小值。无解输出-1
想法：后来的攻击会覆盖之前的攻击。
最矮的那几个区间必须要分别攻击。
然后从矮到高枚举高度，每次计算 加上小于该高度的区间 最少有几个区间。
然后再考虑是否小于k个
11 4
4 1 3 4 2 1 1 2 3 4 2

 */