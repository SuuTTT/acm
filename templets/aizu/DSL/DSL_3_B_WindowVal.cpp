#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    rep(i,1,n){
        cin>>a[i];
    }
     int l=1,r=1;
    int ans=n+1,cur=0;
    while(l<=n&&r<=n){
        //debug(l),debug(r);
        while(r<=n&&mp.size()<k){
            if(a[r]<=k)mp[a[r]]++;
            r++;
            //debug(mp.size());
        }
        //if(mp.size()>=s)ans=min(ans,r-l);
        while(l<r&&mp.size()>=k){
            ans=min(ans,r-l);
            if(a[l]<=k){
                mp[a[l]]--;
                if(mp[a[l]]==0)mp.erase(a[l]);
            }
            l++;
            //debug(mp.size());
        }
    }
    cout<<(ans==n+1?0:ans)<<endl;

}
/* 


 */