#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
map<char,char> counter;
int val[256];
int vis[maxn];
/* 
矛盾的时候只有出的一样的情况。、

 */
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    counter['r']='p';
    counter['p']='s';
    counter['s']='r';
    int n,k;cin>>n>>k;
    cin>>val['r']>>val['s']>>val['p'];
    string s;
    cin>>s;
    
    int ans=0;
    //debug(s);
    rep(i,0,n-1){
        if(vis[i])continue;
        vis[i]=1;
        int ii=i;
        while(ii<=n-1-k&&s[ii]==s[ii+k])ii+=k,vis[ii]=1;
        
        ans+=((ii-i)/k+2)/2*val[counter[s[i]]];
        //debug(i),debug(ii),debug(s[i]),debug(val[counter[s[i]]]),debug(ans);
        //if(ii==i)ans+=val[counter[s[i]]];
    }
   cout<<ans<<endl;
}
/* 

 */