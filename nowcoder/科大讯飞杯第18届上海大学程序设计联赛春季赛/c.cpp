#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string s[2];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s[0]>>s[1];
    if(s[0]!=s[1]){
        cout<<max(s[0].length(),s[1].length())<<endl;
    }else{
        cout<<-1<<endl;
    }

}
/* 
aba
abc
S1!=S1 ans=
 */