#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b;cin>>a>>b;
    if(a<=b)cout<<b-a<<endl;
    else{
        int ans=0;
        while(a>b){
            if(a%2==0){a/=2,ans++;}
            else a++,ans++;
        }
        cout<<ans+b-a<<endl;
    }
    
}
/* 
7 4
7 8 4
7 3 4
15 8


 */