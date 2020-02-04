#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=100005;
typedef long long ll;
struct building{
    ll l,r,h;
    bool operator < (const building& b)const{
        return l==b.l?h<b.h:l<b.l;
    }

}b[maxn];
set<building> s;
bool cmp(building a,building b){
    return a.h>b.h;
}
int main(){
    int n;
    cin>>n;
    rep(i,1,n)scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].h);
    sort(b+1,b+1+n,cmp);
    ll ans=0;
    s.insert(b[1]);
    ans+=b[1].h*(b[1].r-b[1].l);
    s.insert(building{-1,-1,0});
    s.insert(building{(ll)2e9,(ll)2e9,0});
    rep(i,2,n){
        
        ll now=b[i].h*(b[i].r-b[i].l);
        //if(i==3)debug(now);
        //if(i==3)debug(s.size());
        auto it=s.lower_bound(b[i]),it1=it;

        if(it==s.end())it--;
        
        if((*it).l>b[i].r){//1.左分离
           /* ans+=(b[i].r-b[i].l)*b[i].h;
            s.insert(b[i]);
            continue;*/
            
            it--;
        }
        if((*it).l>=b[i].l){
            //左包含多个
            while((*it).r!=(ll)2e9&&(*it).r<=b[i].r){
                now-=b[i].h*((*it).r-(*it).l);
               // debug((*it).l),debug(b[i].h),debug(b[i].r),debug(b[i].h*((*it).r-(*it).l)),debug(now);
                auto dit=it;
                it++;
                s.erase(dit);
            }
            if((*it).l<=b[i].r&&(*it).r>b[i].r){//2.左重叠1个
                
                now-=(b[i].r-(*it).l)*b[i].h;
                b[i].r=(*it).r;
                //if(i==3)debug((*it).l),debug(b[i].h),debug(b[i].r),debug((b[i].r-(*it).l)*b[i].h);
                auto dit=it;
                it--;
                s.erase(dit);
                s.insert(b[i]);
               // if(i==3)debug(now);
            }
        }
       if((*it).r==(ll)2e9)it--;
       //右重叠1个
        if((*it).r>=b[i].l){
            
            now-=((*it).r-b[i].l)*b[i].h;
            b[i].l=(*it).l;
            if((*it).r>=b[i].r)b[i].r=(*it).r,now=0;
            s.erase(it);
        }
        s.insert(b[i]);
        ans+=now;
        
      // debug(now);debug(ans);
    }
    cout<<ans<<endl;
}
/*
3
1 6 3
2 3 4
3 4 4

6
2 6 9
9 14 11
12 20 6
17 25 20
23 31 14
29 36 18
*/