#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef pair<int,int> pii;
#define tim first
#define num second
int vis[maxn],a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t1;cin>>t1;while(t1--){
        int flag=1;
        int n,t;
        cin>>n>>t;
        rep(i,1,n)cin>>a[i];
        fill(vis,vis+4000,-1);
        queue<pii> Q;
        Q.push({0,0});
        vis[0]=0;
        while(!Q.empty()){
            auto cur=Q.front();
           // debug(cur.tim),debug(cur.num);
            Q.pop();
            if(cur.tim==t){
                cout<<cur.num<<' '<<0<<endl;
                flag=0;break;
            }
                rep(i,1,n){
                    int curt=cur.tim+a[i];
                    curt=min(curt,3600),curt=max(curt,0);
                    if(vis[curt]==-1){
                        Q.push({curt,cur.num+1});
                        vis[curt]=cur.num+1;
                    }
            }

        }
        if(flag){
        int ans=4000,ans1=0;
        rep(i,0,3600)if(t-i<0&&vis[i]!=-1){
            
            ans=i-t,ans1=vis[i];break;
        }
        cout<<ans1<<' '<<ans<<endl; 
        }
    
    }
    
    
}