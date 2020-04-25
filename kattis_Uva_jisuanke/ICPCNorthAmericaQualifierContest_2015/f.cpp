#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int cnt[256];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;getchar();
    rep(i,1,n){
        string line;
        getline(cin,line);
        debug(line);
        rep(i,'a','z')cnt[i]=0;
        for(auto c:line){
            //debug(c);
            cnt[c]++;
            if(c>='A'&&c<='Z')cnt[c-'A'+'a']++;
        }    
        string ans;
        rep(i,'a','z')if(cnt[i]==0)ans+=(char)i;
        if(ans.empty())cout<<"pangram"<<endl;
        else cout<<"missing "<<ans<<endl;
    }
}
/* 
3
The quick brown fox jumps over the lazy dog.
ZYXW, vu TSR Ponm lkj ihgfd CBA.
.,?!’" 92384 abcde FGHIJ

 */