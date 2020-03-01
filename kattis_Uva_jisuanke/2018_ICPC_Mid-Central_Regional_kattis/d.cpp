#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int cnt[256];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    rep(i,1,5){
        cin>>s;
        cnt[s[0]]++;
    }
    int ans=0;
    rep(i,0,255)ans=max(ans,cnt[i]);
    cout<<ans<<endl;
}