#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
void prefix_function(string s,vector<int>& pi) {
    int n = (int)s.length();
     pi.resize(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    //for(auto t:pi)debug(t);
    //return pi;
}
string s[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;rep(i,1,n)cin>>s[i];
    int q;cin>>q;while(q--){
        int l,r;cin>>l>>r;
        string t=s[r]+'#'+s[l];
        int len=s[r].size();
        vector<int>p;
        prefix_function(t,p);
        cout<<p.back()<<endl;
    }
}
/* 
3
AAAA
ACGT
AACCGGTT
1
2 3
T 忘记注释debug
 */