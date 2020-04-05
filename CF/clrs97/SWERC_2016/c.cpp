#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int d,r,t;
    cin>>d>>r>>t;
    int x=3;
    while((x+3)*(x-2)/2+(x+d+4)*(x+d-3)/2!=r+t){
        x++;
    }
    
    cout<<(x+3)*(x-2)/2-t<<endl;

}
/* 

 */