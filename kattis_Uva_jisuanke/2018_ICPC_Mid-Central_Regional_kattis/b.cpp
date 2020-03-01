#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k;
    cin>>k;
    string s1,s2;
    cin>>s1>>s2;
    int l=s1.size();
    int s=0;
    rep(i,0,l-1){
        if(s1[i]==s2[i])s++;
    }
    int ans=0;int n=l;
    if(k<=s)ans=k+n-s;
    else{
        ans=s+n-s-(k-s);
    }
    cout<<ans<<endl;
}
/* 
s
n-s
k

3
FTFFF
TFTTT
 */