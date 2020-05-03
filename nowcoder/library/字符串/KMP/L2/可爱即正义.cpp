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
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s="suqingnianloveskirito";
    int sl=s.length();debug(sl);
    s+='#';
    string t;cin>>t;
    int tl=t.length();
    s+=t;
    auto p=prefix_function(s);
    vector<int> v;
    rep(i,0,sl+tl){
        if(p[i]==sl)v.push_back(i);
    }
    if(v.size()==0){
        rep(i,2,tl){
            swap(s[sl+1],s[sl+i]);
            p=prefix_function(s);
            rep(j,0,sl+tl){
                if(p[j]==sl){swap(s[sl+1],s[sl+i]);break;}
            }
            {cout<<"Yes\n"<<1<<' '<<i<<endl;return 0;}
        }
    }
    if(v.size()==1){
        cout<<"Yes\n"<<v[0]-sl<<' '<<v[0]-sl-1<<endl;
    }
    if(v.size()==2){
        cout<<"Yes\n"<<v[0]-sl<<' '<<v[1]-sl-1<<endl;
    }
    if(v.size()>=3){
        cout<<"No"<<endl;
    }
    
}
/* 
交换t两个字符使得串s不出现
t中没有s 调换任意，不出现
1个s 调换串内地字符
2个s 调换两个串不同的字符
3个s 无解

1TLE line 38写错+logic问题
 */