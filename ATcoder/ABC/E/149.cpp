#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;

long long a[maxn],cnt[maxn];
long long sum[maxn];
int n,m;
bool check(int x){  
    int tot=0;
    int y=0;
    rep(i,1,n)y=x-a[i],tot+=cnt[y>0?y:0];
    return tot>=m;
}
signed main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;rep(i,1,n)cin>>a[i];
    //sort(a+1,a+1+n);
    rep(i,1,n){cnt[a[i]]++;sum[a[i]]+=a[i];}
    for(int i=200000;i>=0;i--)cnt[i]+=cnt[i+1],sum[i]+=sum[i+1];
    long long l=1-1,r=200000+1;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    debug(r);
    long long ans=0,tot=0;
    int y=0;
    rep(i,1,n)y=max(0ll,r-a[i]),ans+=sum[y]+a[i]*cnt[y],tot+=cnt[y];
    
    ans-=r*(tot-m);
    
    cout<<ans<<endl;
}



/* 
n^2 的数据里取前k大，
数据的构造方法是数列两两取和
Ai<1e5
二分所有选的数的下界的最小值x。满足 bi>x 的bi数量小于等于m的最大值

5 3
10 14 19 34 33
68+67=135

9 14
1 3 3 5 5 21 24 34 110 
wa1 cnt 数组下届是0 not 1
wa2 y>1e5?1e5:y  为啥错了？
 */