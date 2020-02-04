#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
typedef long long ll;
const int maxn=100005;
struct S{
    ll pos,h,f;
    operator < (const S& r) const{
        return pos==r.pos?h<r.h:pos<r.pos;
    }
}s[maxn*2];

int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    int l,r,h;
    rep(i,1,n){scanf("%d%d%d",&l,&r,&h);
        s[++cnt]={l,h,0};
        s[++cnt]={r,h,1};
    }
    sort(s+1,s+1+cnt);
    int las=0;ll ans=0;
    multiset<ll,greater<ll> > st;
    rep(i,1,cnt){
        if(!st.empty())ans+=(*st.begin())*(s[i].pos-las);
        debug(i),debug(ans),debug(st.size());
        if(s[i].f)st.erase(st.find(s[i].h));
        else st.insert(s[i].h);
        las=s[i].pos;
        
    }
    cout<<ans<<endl;
}
/*
2
1 3 1
2 4 1

6
2 6 9
9 14 11
12 20 6
17 25 20
23 31 14
29 36 18
*/