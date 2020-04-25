#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef unsigned long long ll;
ll BASE=29,mod=(ll)998244353;
map<ll,int> mp;
unordered_set<ll> st;
ll tmp=0;
ll bit=1;
void fix(ll &tmp){tmp%=mod;tmp+=mod;tmp%=mod;}
ll hs(string s){ll tmp=0;for(auto c:s){ tmp*=BASE;tmp+=c-'a';}return tmp;}
char ss[maxn];
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    string s;scanf("%s",&ss);
    s=ss;
    auto len=s.length();
    
    tmp=hs(s);
    rep(i,1,len-1){bit*=BASE;}
    for(auto c:s){
        st.insert(tmp);
       
        tmp-=bit*(c-'a');
        
        tmp*=BASE;
        tmp+=(c-'a');
        
        //debug(tmp);
    }st.insert(tmp);
    int n;cin>>n;
    rep(i,1,n){
        scanf("%s",&ss);s=ss;
        if(s.length()<len){cout<<0<<endl;continue;}
        tmp=0;
        tmp=hs(s.substr(0,len));
        
        int ls=s.length();
        int ans=0;
        if(st.count(tmp))ans++;
        
        rep(i,0,ls-len-1){
            
            tmp-=(s[i]-'a')*bit;
            
            tmp*=BASE;
            tmp+=(s[i+len]-'a');
            
            //debug(tmp);
            if(st.count(tmp))ans++;
        }
        
        cout<<ans<<endl;
    }
}
/* 
abab
2
abab
ababcbaba

abab
2
abababab
ababcbaba

t 1e7个字符,unordered_set
wa mod
 */