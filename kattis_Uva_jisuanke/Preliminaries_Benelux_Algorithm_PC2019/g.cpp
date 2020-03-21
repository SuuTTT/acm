#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int len=s.length();
    string ans="h";
    len-=2;
    rep(i,1,len*2)ans+='e';
    ans+='y';
    cout<<ans<<endl;
}

/* 
1234
123

123a
123

a123
123

c0deninja5
c0deninja

abc
ABC

pa55WORD
PA55word
 */