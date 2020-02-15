#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
typedef unsigned int ll;
const int maxn=(int)1e6+5;
inline void init_hash(int l,string s,ll *h){
    h[0]=0;
    rep(i,1,l)h[i]=h[i-1]*BASE + s[i-1];
    base[0]=1;
    rep(i,1,l)base[i]=base[i-1]*BASE;
}
inline ll string_hash(ll *h,int l,int r){
    return h[r]-h[l]*base[r-l];
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}