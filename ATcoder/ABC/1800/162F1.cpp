#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+7;
ll dp[N][2];
ll arr[N];
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)  cin>>arr[i];
    dp[2][0]=arr[1];
    dp[2][1]=arr[2];
    for(ll i=3;i<=n;i++){
        if(i&1){
            dp[i][1]=max({dp[i-2][1],dp[i-2][0],dp[i-3][1],dp[i-3][0]})+arr[i];
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        }
        else {
            dp[i][1]=max(dp[i-2][1],dp[i-2][0])+arr[i];
            dp[i][0]=arr[i-1]+dp[i-2][0];
        }
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
    return 0;
}