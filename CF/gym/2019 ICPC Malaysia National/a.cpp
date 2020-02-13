#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e3+5;
int val[maxn];
#define pii pair<int,int>
#define idx first
#define val second
char mp[maxn][maxn],tmp[maxn][maxn];

char rot(char c){
    //>v<^
    if(c=='>')return 'v';
    if(c=='v')return '<';
    if(c=='<')return '^';
    if(c=='^')return '>';
    return '.';
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string op;
    cin>>op;
    rep(i,1,n)cin>>mp[i]+1;
    //rep(i,1,n)cout<<mp[i]+1<<endl;
    int rs=0;
    for(auto c:op)c=='R'?rs++:rs+=3;
    rs%=4;
    while(rs--){
        rep(i,1,n)rep(j,1,n){
            tmp[j][n-i+1]=rot(mp[i][j]);
        }
        rep(i,1,n)rep(j,1,n){
            mp[i][j]=tmp[i][j];
        }
    }
    rep(i,1,n)cout<<mp[i]+1<<endl;
}
/* 
3 R
>v>
...
<^< */