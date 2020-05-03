#include <bits/stdc++.h>

using namespace std;
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
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    while(cin>>s){
        if(s==".")break;
        vector<int> p=prefix_function(s);
        int n=p.size();
        int k=n-p.back();
        cout<<(n%k==0?n/k:1)<<endl;
    }
}