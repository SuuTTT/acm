#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int l;
    string s;
    cin>>l>>s;
    if(s=="G")cout<<"OK"<<endl;
    else if(s=="PG"){
        if(l<13)cout<<"OK IF ACCOMPANIED"<<endl;
        else cout<<"OK"<<endl;
    }
    else {
        int x=s[3]-'0';
        if(l<x+10)cout<<"ACCESS DENIED"<<endl;
        else cout<<"OK"<<endl;
    }
}

/* 
18 R-18
Frozen 3
 */