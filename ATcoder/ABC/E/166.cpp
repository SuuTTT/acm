#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
long long a[maxn],ans;
unordered_map<int,long long> mp;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;rep(i,1,n)cin>>a[i];
    for(int i=n;i>=1;i--){
        if(mp.count(a[i]+i))ans+=mp[a[i]+i];
        mp[i-a[i]]++;
    }
    cout<<ans<<endl;
}
/* 
multi_set T
i>j:
Ai+Aj=i-j
Ai-i=-j-Aj
i<j:
Ai+Aj=j-i
Ai+i=j-Aj
 */