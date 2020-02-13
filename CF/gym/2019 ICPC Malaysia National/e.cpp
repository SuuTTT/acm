#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e3+5;
int f[maxn],v[maxn],w[maxn];
int path[maxn][maxn];
vector<int> ans[50];
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int C;
    while(cin>>C){
        if(C==0)break;
        int n;
        cin>>n;
        rep(i,1,n){
            cin>>v[i];w[i]=v[i];
        }
        rep(i,0,C)f[i]=0,ans[i].clear();
        for(int i=n;i>=1;i--)
        {
            for(int c=C;c>=0;c--)
            {
                if(c>=w[i]){
                    if(f[c]<=f[c-w[i]]+v[i]){
                        f[c]=max(f[c],f[c-w[i]]+v[i]);
                        ans[c]=ans[c-w[i]];
                        ans[c].push_back(v[i]);
                        //debug(c);
                        //for(auto t:ans[c])cout<<t<<' ';cout<<endl;
                    }
                    
                }
                
            }
        }
    
    reverse(ans[C].begin(),ans[C].end());
    for(auto t:ans[C])cout<<t<<' ';
    cout<<f[C]<<endl;
    }
}
    
    

/*
10 9 11 9 3 5 8 4 9 3 2
0
*/