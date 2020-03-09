#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int cnt[256];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin>>s;int len=s.length();
    rep(i,0,len-1){
        if(i%2)cnt[s[i-1]]++;
/*         if(cnt['A']==10&&cnt['B']==10){

        } */
    }
   cout<<(cnt['A']>cnt['B']?"A":"B")<<endl;

}
/* 
A2B1A2B2A1A2A2A2
 */