#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
map<int,int> mp;
void putS(int x){
    while(x){
        cout<<' ';x/=10;
    }
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    rep(T,1,t){
        printf("Prime Factorization #%d:\n",T);
        int n;cin>>n;
        mp.clear();
        rep(i,1,n){
            int x,y;
            cin>>x>>y;
            mp[x]+=y;
        }
        for(auto p:mp){
            putS(p.first);
            cout<<p.second;
        }
        cout<<endl;
        for(auto p:mp){
            cout<<p.first;
            putS(p.second);
        }
        cout<<endl;cout<<endl;
    }
}
/* 
3
3 2 5 101 17 3 13
4 5 2 5 19 3 5 11 1
5 2 10 3 11 2 12 3 13 2 14
 */