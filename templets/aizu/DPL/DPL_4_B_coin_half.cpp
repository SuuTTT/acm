#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
 
ll N,K,L,R;
ll a[40];
 
vector< P > x,y;
 
void pt(int si,int ti,vector< P > &x){
  int num=ti-si;//左闭右开
  for(int S=0;S<(1<<num);S++){//枚举2^n种取法，记录pair<#Coin,value>
    ll sum=0,cnt=0;
    for(int j=0;j<num;j++)
      if(S>>j&1)
        sum+=a[si+j],cnt++;
    x.push_back(P(cnt,sum));
  }
}
 
int main(){
  cin>>N>>K>>L>>R;
  for(int i=0;i<N;i++)cin>>a[i];
  pt(0,N/2,x);
  pt(N/2,N,y);
 
  sort(y.begin(),y.end());
   
  ll ans=0;
  for(int i=0;i<(int)x.size();i++){
    vector< P > :: iterator itl,itr;
    itl=lower_bound(y.begin(),y.end(),P(K-x[i].first,L-x[i].second));
    itr=upper_bound(y.begin(),y.end(),P(K-x[i].first,R-x[i].second));
    ans+=(itr-itl);
  }
  cout<<ans<<endl;
  return 0;
}
