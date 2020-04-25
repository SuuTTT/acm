#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int cnt[256],mx;
string s;
void yes_sort(){
    puts("YES");sort(s.begin(),s.end());cout<<s<<endl;
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s;
    int len=s.length();
    int n=len/2;string ans;
    for(auto c:s)cnt[c]++,mx=max(cnt[c],mx);
    if(mx==len){puts("NO");return 0;}
    if(mx==len-1){if(len==2)yes_sort();else puts("NO");}
    if(mx<=n){yes_sort();return 0;}
    if(mx==len-2){
        if(len==4){yes_sort();return 0;}
        int ok=1;rep(i,'a','z')if(cnt[i]==2)ok=0;
        if(!ok)puts("NO");
        else{
            char c;string tmp;
            rep(i,'a','z'){if(cnt[i]==mx)c=i; if(cnt[i]==1)tmp+=(char)i;}
            ans+=tmp[0];rep(i,1,n-1)ans+=c;
            ans+=tmp[1];rep(i,1,n-1)ans+=c;
            puts("YES");
            cout<<ans<<endl;
        }
        return 0;
    }
    char c;string tmp;
    rep(i,'a','z'){if(cnt[i]==mx)c=i;}
    rep(i,'a','z')if(i!=c){
        rep(j,1,cnt[i])tmp+=(char)i;
    }
    ans+=tmp.back();tmp.pop_back();
    rep(i,1,n)ans+=c;
    ans+=tmp;
    rep(i,1,mx-n)ans+=c;
    puts("YES");
    cout<<ans<<endl;
}
/* 
cc
cd
cccd
ccccaa
ccccab

cbbabcacbb

cbbabcacbbbb
 */