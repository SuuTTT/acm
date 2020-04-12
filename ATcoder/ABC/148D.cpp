#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int cur=1;
    rep(i,1,n){
        int x;cin>>x;
        if(x==cur)cur++;
    }
    cout<<(cur==1?-1:n-cur+1)<<endl;
}
/* 
贪心，拿第一个合法的。 不会更优
3
2 1 2
 */