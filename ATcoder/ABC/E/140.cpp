#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
typedef pair<int,int> pii;
#define X first
#define Y second
pii p[maxn];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n){cin>>p[i].X;p[i].Y=i;}
    sort(p+1,p+1+n,greater<pii>());
    multiset<int> st;
    st.insert(0);st.insert(0);st.insert(n+1),st.insert(n+1);
    int ans=0;
    rep(j,1,n){
        
        int i=p[j].Y;
        auto it=st.lower_bound(i);
        int yi=*it;
        int zi=*(++it);it--;
        int xi=*(--it);
        int wi=*(--it);
        ans+=((xi-wi)*(yi-i)+(zi-yi)*(i-xi))*p[j].X;//debug(ans);
        st.insert(i);
    }
    cout<<ans<<endl;
}
/* 
core
1. decreasing add to set
2. wi  xi  i  yi  zi   (xi-wi)*(yi-i)+(zi-yi)*(i-xi)
eg
3
2 3 1
2*2+1
2*()

lesson
it--, use math is simplify of problem
 */