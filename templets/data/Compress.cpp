#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sort(hs,hs+hn);
	hn=unique(hs,hs+hn)-hs;
}

/* 
int getID(int x) { return lower_bound(vp.begin(), vp.end(), x) - vp.begin() + 1; };//x=vp[id];
rep(i, 1, N) scanf("%d", &A[i]), vp.pb(A[i]);
sort(vp.begin(), vp.end()), vp.erase(unique(vp.begin(), vp.end()), vp.end());




 */