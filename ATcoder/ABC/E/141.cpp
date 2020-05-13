#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int l;string s;
    cin>>l>>s;
    int ans=0;
    rep(i,0,l-1){
        //debug(s.substr(i));
        vector<int> z=z_function(s.substr(i));
        for(int j=0;j<z.size();j++){
            ans=max(ans,min(j,z[j]));
        }
    }
    cout<<ans<<endl;
}

/* 
s的最长重复子串
二分+ hash or 后缀数组
Zfunction
 */