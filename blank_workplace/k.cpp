#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll x[maxn],y[maxn];
pair<ll, ll> p[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n){
        cin>>x[i];
    }
    rep(i,1,n)cin>>y[i];
    rep(i,1,n)p[i]={y[i],x[i]};
    sort(p+1,p+1+n);
    rep(i,1,n)cout<<p[i].second<<(i==n?'\n':' ');
}
/* 
3
2 1 4
1 4 3
 */