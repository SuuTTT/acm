#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long ans=(1ll<<n)-1,cur=0;;
    
    rep(i,1,n){
		string s;
		cin>>s;
		//if(s[0]=='Z')b.push_back(1);else b.push_back(0);
        cur<<=1ll;
        if(s[0]=='Z')cur+=1;
	}
    cout<<ans-cur<<endl;
}
/* 
3
Z
O
Z
 */