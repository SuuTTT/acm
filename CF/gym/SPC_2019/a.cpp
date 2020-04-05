#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    string a,b;
    cin>>n>>a>>b;
    int i=0,j=0;
    while(i<n&&a[i]==b[j])i++,j++;
    if(i==n){cout<<"NO"<<endl;return 0;}
    if(a[i]<b[j]){
        rep(k,i,n-1)if(a[k]>b[k]){
            cout<<"YES"<<endl;
            cout<<i+1<<' '<<k+1<<endl;
            return 0;
        }
        cout<<"NO"<<endl;return 0;
    }else{
        if(i>=1){
             cout<<"YES"<<endl;
            cout<<0+1<<' '<<i+1<<endl;
            return 0;
        }else{//i=0
            if(n>2){
                cout<<"YES"<<endl;
                cout<<1+1<<' '<<2+1<<endl;
                return 0; 
            }else{//n=2
                reverse(a.begin(),a.end());
                reverse(b.begin(),b.end());
                if(a>b){
                    cout<<"YES"<<endl;
                cout<<1<<' '<<2<<endl;
                return 0; 
                }else cout<<"NO"<<endl;
            }
        }
    }
}
/*
2 
ab
ba

2
ba
ab
 */