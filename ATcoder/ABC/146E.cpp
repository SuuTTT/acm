#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll a[maxn];
map<ll,int> mp;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,k;cin>>n>>k;
    rep(i,1,n) {cin>>a[i];a[i]+=a[i-1];}
    rep(i,1,n){a[i]=(a[i]-(ll)i+k)%k;}//+k，不+k 都一样？？ 因为a[i]>=1，不会负数
    ll ans=0;
    
    rep(j,0,n){//a[0]=0
        if(j>=k)mp[a[j-k]]--;
        if(mp.count(a[j]))ans+=mp[a[j]];
        mp[a[j]]++;
    }
    cout<<ans<<endl;
}
/* 
1 2
1

5 4
1 4 2 3 5

求# str S: sum(S) mod k == len(S)
sum[j]-sum[i] mod k == j - i
sum[j]-j== sum[i]-i  j-i<k

trick

partial_sum(begin(a), end(a), begin(a));
 */