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
unordered_map<ll,int> mp;
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
vector<int> ans;
int get(int x){
    int ret=0;
     mp.clear();
    rep(i,0,len-x){
        ll sh=string_hash(h,i,i+x);
        //debug(i),debug(sh);
        mp[sh]++;
        if(mp[sh]>=n)ans.push_back(i);
    }
    return ret+1;
}
int main(){
   // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    n=2;
    scanf("%s",s);
    len=strlen(s);
    init_hash(len,s,h);
    int l=0,r=len+1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    get(r);
    int mn=ans[0];
    for(auto t:ans){
        //debug(t);
        int flag=0;
        int p1=mn,p2=t;
        while(p2<len&&p1<len&&s[p1]==s[p2])p1++,p2++;
        if(p2==len)continue;
        if(s[p2]<s[p1])mn=t;
    }
    rep(i,mn,mn+r-1)cout<<s[i];
    cout<<endl;
}
/* 
acacababa

ababacaca
bbcaadbbeaa


abcefgabc

abcbabcba

abcdabab

bbcaadbbeaaee

aabbccddeef
aabbaac

bbcaabbdaacccaad
 */