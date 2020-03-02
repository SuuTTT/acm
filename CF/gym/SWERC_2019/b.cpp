#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
map<string,int> mp;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int t=n;
    while(t--){
        string s;
        cin>>s;
        mp[s]++;
    }
    pair<string,int> ans=*mp.begin();
    int flag=0;
    for(auto p:mp){
       if(p.second>ans.second)ans=p;
    }
    debug(ans.second);
    if(ans.second<=n-ans.second)cout<<"NONE"<<endl;
    else cout<<ans.first<<endl;
    

}
/* 
3
frog
fish
frog

4
cat
mouse
mouse
cat
 */