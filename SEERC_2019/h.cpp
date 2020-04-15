#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

ll n,ans;
vector<ll> a,b;

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n){
        a.resize(n);
        b.resize(n);
        for(auto &i:a)cin>>i;
        for(auto &i:b)cin>>i;

        for(auto i:a){
			ll mn=(int)1e9+5;
			for(auto j:b){
				mn=min(mn,abs(i-j))
			}
			ans=max(ans,mn);
		}
        cout<<ans<<endl;
    }
    return 0;
}
/*
bob 有一个策略可以取到与alice最后剩的数 abs最小的数。
每次alice删掉a_i, bob求出剩下的a_i留到最后会对应的b_i的集合,删掉集合外的一个b_i即可。

a_i对应b_i的意思是如果alice最后剩下a_i,bob剩下b_i 使得|a_i-b_i|最小。
4
2 14 7 14
5 10 9 22
*///
