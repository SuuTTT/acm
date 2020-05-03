#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
long long A[maxn],B[maxn],C[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x,y,a,b,c;cin>>x>>y>>a>>b>>c;
    vector<long long> D;
    long long ans=0;
    rep(i,1,a)cin>>A[i];rep(i,1,b)cin>>B[i];rep(i,1,c)cin>>C[i];
    sort(A+1,A+1+a);sort(B+1,B+1+b);sort(C+1,C+1+c);
    rep(i,1,x)D.push_back(A[a+1-i]);
    rep(i,1,y)D.push_back(B[b+1-i]);
    sort(D.begin(),D.end()); 
    int i=0;
    while(i<D.size()&&i<c&&D[i]<C[c-i])D[i]=C[c-i],i++;//贪心，大的和小的比，很关键。只证明了大的和大的不是最优的。
    for(auto t:D)ans+=t,debug(t);
    cout<<ans<<endl;
}
/* 
贪心，
 */