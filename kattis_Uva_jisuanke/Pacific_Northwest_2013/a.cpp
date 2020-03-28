#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int v[maxn],f[maxn],c[maxn];
int n,d;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        rep(i,1,n){
            cin>>v[i]>>f[i]>>c[i];
            if(d*c[i]<=f[i]*v[i])ans++;
        }
        cout<<ans<<endl;
    }
}