#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)5e6+5;
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
    return pi;
}
char ch[17];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;string s;cin>>n>>s;int len=s.size();
    rep(i,0,9)ch[i]=i+'0';
    rep(i,10,15)ch[i]=i-10+'A';
    rep(base,2,16){
        string t;
        for(int i=n;i>=1;i--){
            int tmp=i;
            while(tmp){
                t+=ch[(tmp%base)];
                tmp/=base;
            }
        }
        reverse(t.begin(),t.end());
         string tmp=s;s+='#';s+=t;
        /* auto p=prefix_function(s);
        for(auto t:p)if(t==len){
            cout<<"yes"<<endl;return 0;
        } */
    }
   
    cout<<"no"<<endl;
}