#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    //for(auto t:pi)debug(t);
    return pi;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--){
        string s;cin>>s;
        int l=s.length();
        int ans=0;
        rep(j,1,l){
            string t=s.substr(l-j,j)+'#';
            
            t+=s.substr(0,l);
           // debug(t);
            auto p=prefix_function(t);
            int b=0;
            rep(i,j+1,j+l) b=p[i],ans^=b*b*(i-j-b)*(j-b);
        }
        cout<<ans<<endl;
    }
}
/* 
T 复杂度n^3
wr 边界打错,ij打反
 */