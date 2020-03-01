#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long x;cin>>x;
    //x=(1<<31);
    bitset<32> b(x);
    cout<<b<<endl;
    cout<<(~b)<<endl;
    cout<<(b<<1)<<endl;
    cout<<(b>>1)<<endl;
}
