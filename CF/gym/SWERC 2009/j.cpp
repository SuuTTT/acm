#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef unsigned int ll;
int n;
const ll BASE=233;
ll h[maxn],base[maxn];
char s[maxn];
inline void init_hash(int l,char* s,ll *h){
    h[0]=0;
    rep(i,1,l)h[i]=h[i-1]*BASE + s[i-1];
    base[0]=1;
    rep(i,1,l)base[i]=base[i-1]*BASE;
}
inline ll string_hash(ll *h,int l,int r){
    return h[r]-h[l]*base[r-l];
}
int H[maxn];
map<ll,int> mp;
 int len;
bool check(int x){
    mp.clear();
    rep(i,0,len-x){
        ll sh=string_hash(h,i,i+x);
        mp[sh]++;
        if(mp[sh]>=n)return 1;
    }
    return 0;
}
int get(int x){
    int ret=0;
     mp.clear();
    rep(i,0,len-x){
        ll sh=string_hash(h,i,i+x);
        mp[sh]++;
        if(mp[sh]>=n)ret=i-1;
    }
    return ret+1;
}
int main(){
   // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    
    while(scanf("%d",&n)){
        if(n==0)break;
        scanf("%s",s);
        len=strlen(s);
        init_hash(len,s,h);
        int l=0,r=len+1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        if(r==0)printf("none\n");
        else printf("%d %d\n",r,get(r));

    }
}
/* 
3
baaaababababbababbab
11
baaaababababbababbab
3
cccccc
0
 */