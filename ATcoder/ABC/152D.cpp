#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
map<int,int> mp;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int ans=0;
    rep(i,1,n){
        int ii=i;while(ii>9)ii/=10;
        
        int id=i%10+ii*10;
         /*
        int inv=i%10*10+ii;
        
        if(i==0||ii==10)continue;
        
        ans+=2*mp[inv];
        //debug(i),debug(id),debug(inv),debug(mp[inv]);
        if(ii==i%10)ans++; */
        mp[id]++; 
    }
    rep(i,0,9)rep(j,0,9){
        ans+=mp[i*10+j]*mp[j*10+i];
    }
    cout<<ans<<endl;
}