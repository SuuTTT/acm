#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    if(n==1){
        cout<<1<<endl;
        cout<<1<<endl;
    }
    else if(n==2){
        cout<<2<<endl;
        cout<<1<<endl;
        cout<<"00"<<endl;return 0;
    }
    else{
        cout<<n-1<<endl;
        rep(i,0,n-2){
        cout<<0;
        rep(j,1,i)cout<<1;
        cout<<0;
        cout<<endl;
        }
    }
}
/* 
wr cout<<00<<endl;
1
1

2
1
00

3
1
00

4
00
110

4
00
110
1010
11111

 */