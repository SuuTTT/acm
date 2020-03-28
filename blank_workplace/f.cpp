#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m;cin>>m;while(m--){
        int n;
        cin>>n;
        rep(i,1,n)cin>>a[i];
        int round=0;
        int flag=1;
        int st=1;
        while(st<=n){
            flag=1;
            rep(i,st,n){
                if(a[i]!=0)flag=0;
            }
            if(flag)break;
            for(int i=n;i>st;i--){
                a[i]-=a[i-1];
            }
            st++;
            round++;
        }
        if(st>n){
            if(a[n]>0)cout<<"*fizzle*"<<endl;
            if(a[n]<0)cout<<"*bunny*"<<endl;
        }
        if(flag){
            rep(i,1,round)cout<<'z';
            cout<<"ap!"<<endl;
        }
    }
}
/*
2
1 0
1 0 0 
4
2 1 1
5 1 3 6 10 15
5 1 2 4 8 16
2 1 0

 */