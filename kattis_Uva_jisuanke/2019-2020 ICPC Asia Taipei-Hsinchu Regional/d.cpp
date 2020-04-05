#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s[3];
    rep(i,0,2)cin>>s[i];
    int cnt=0;
    rep(i,0,2){
        if(s[i]=="tapioka")continue;
        if(s[i]=="bubble")continue;
        else {cnt++,cout<<s[i]<<' ';}
    }
    if(cnt==0)cout<<"nothing"<<endl;
}
/* 

"bubble tea" or "tapioka"
 */