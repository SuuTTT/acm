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
   // for(auto t:pi)debug(t);
    return pi;
}
int cnt[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    auto p=prefix_function(s);
    for(auto i=p.begin();i<p.end()-1;i++)cnt[*i]++;
    int cur=s.length()-1;
    int ans=0;
    while(cur>0){
        debug(cur);
        if(cnt[p[cur]]){ans=p[cur];break;}
        cur=p[cur]-1;
    }
   
    
    string ss=s.substr(0,ans);
    cout<<(ans?ss:"Just a legend")<<endl;
}
/* 
前缀后缀字符串内各出现一次， 
等价于pi[n-1] 出现了两次， 
考虑到下面的样例
abcabcabc
需要跳fail指针
wr index_0
 */