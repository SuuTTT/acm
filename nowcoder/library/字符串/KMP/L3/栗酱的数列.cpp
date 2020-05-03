#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
vector<int> prefix_function(vector<int> s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
   // for(auto t:pi)debug(t);
    return pi;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--){
        int n,m,k;cin>>n>>m>>k;
        vector<int> a(n),b(m);
        rep(i,0,n-1){cin>>a[i];a[i]%=k;}
        rep(i,0,n-2)a[i]-=a[i+1],a[i]+=k,a[i]%=k;a.pop_back();
        rep(i,0,m-1){cin>>b[i];b[i]%=k;}
        rep(i,0,m-2)b[i]-=b[i+1],b[i]%=k,b[i]+=k,b[i]%=k,b[i]=-b[i],b[i]+=k,b[i]%=k,debug(b[i]);b.pop_back();
        b.push_back(-1);
        rep(i,0,n-2)b.push_back(a[i]);
        //for(auto t:b)debug(t);
        auto p=prefix_function(b);
        int ans=0;
        for(auto t:p)if(t==m-1)ans++;
        cout<<ans<<endl;
    }
}
/* 
数学变型->kmp
a1+b1=a2+b2
a1-a2=b2-b1
2 3 2
3 2

2 3 4
3 2


2
3 2 5
7 8 7
8 7

3 2 5
7 8 9
8 7
 */