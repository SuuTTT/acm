#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
vector<int> V;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n){int x;cin>>x;V.push_back(x);}
    V.erase(unique(V.begin(),V.end()),V.end());
    int cnt=0;
    for(auto t:V)cout<<t<<(++cnt==V.size()?'\n':' ');

}
/* 

 */