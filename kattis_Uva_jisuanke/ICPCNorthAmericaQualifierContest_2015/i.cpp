#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;

int main(){
    int n;cin>>n;getchar();
    rep(i,1,n){
        string line;
        getline(cin,line);
        if(line.substr(0,10)=="Simon says"){
            cout<<line.substr(10)<<endl;
        }
        
    }
}

/* 

 */