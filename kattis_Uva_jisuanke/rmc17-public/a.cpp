#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int flag=0;
    for(int i=0,l=s.size();i<l-1;i++){
        if(s[i]=='s'&&s[i+1]=='s')flag=1;
    }
    cout<<(flag?"hiss":"no hiss")<<endl;
}