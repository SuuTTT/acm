#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
bool check(int x){
    vector<int> tmp;
    while(x)tmp.push_back(x%10),x/=10;
    rep(i,0,3)if(tmp[i]!=tmp[5-i])return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;while(n--){
        int x;cin>>x;
        int d=0;
        while(1){
            if(x+d<1000000&&check(x+d))break;
            if(x-d>=100000&&check(x-d))break;
            d++;
        }
        if(x-d>=10000&&check(x-d))cout<<x-d<<endl;
        else cout<<x+d<<endl;
    }
}