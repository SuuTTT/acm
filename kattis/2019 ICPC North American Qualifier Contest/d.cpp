#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int vis[201];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int mx=0;
    rep(i,1,n){
        int x;
        cin>>x;
        vis[x]=1;
        if(i==n)mx=x;
    }
    int flag=0;
    rep(i,1,mx){
        if(vis[i]==0)flag++,cout<<i<<endl;
    }
    if(flag==0)cout<<"good job"<<endl;

}