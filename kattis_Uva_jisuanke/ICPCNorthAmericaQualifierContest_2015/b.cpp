#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll ncr[5000][5000];

ll nCr(ll n,ll r){
  if(n==r)return 1;
  if(r==0)return 1;
  if(ncr[n][r])return ncr[n][r];
  ncr[n][r]=(nCr(n-1,r-1)+nCr(n-1,r));
  return ncr[n][r];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--){
        double r,s,x,y,w;
        cin>>r>>s>>x>>y>>w;
        double p=(s-r+1)/s;
        double ans=0;
        for(double i=x;i<=y;i++){
             ans+=pow(p,i)*pow(1-p,y-i)*nCr(y,i);
        }
        
       
       // debug(p),debug(ans);
        
        cout<<(w*ans-1>1e-8?"yes":"no")<<endl;
    }
}