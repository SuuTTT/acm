#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;

struct edge{
    ll to,a,b;
};
struct Data{
    ll v,s,t;
    bool operator < (const Data & a)const{return t>a.t;}
};

const ll  MAXN=50,MAXS=MAXN*50,INF=1e18;
ll dp[MAXN+1][MAXS+1];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,m,s;cin>>n>>m>>s;
    vector<edge> E[MAXN+1];
    rep(i,1,m){
        int u,v,a,b;
        cin>>u>>v>>a>>b;
        E[u].push_back((edge){v,a,b});
        E[v].push_back((edge){u,a,b});
    }
    vector<int> c(n+1),d(n+1);
    rep(i,1,n){
        cin>>c[i]>>d[i];
    }
    s=min(s,MAXS);
    rep(i,1,n)rep(j,0,MAXS)dp[i][j]=INF;dp[1][s]=0;
    priority_queue<Data> Q;
    Q.push((Data){1,s,0});
    while(!Q.empty()){
        Data dt=Q.top();Q.pop();
        //debug(dt.v),debug(dt.s),debug(dt.t);
        //if(dt.s<0)continue;
        if(dt.t>dp[dt.v][dt.s])continue;
        //change
        ll curt=dp[dt.v][dt.s];//or dt.t 都行
        ll ns=min(dt.s+c[dt.v],MAXS);
        ll nt=curt+d[dt.v];//?dp[dt.v][dt.s]+d[dt.v]
        if(dp[dt.v][ns]>nt){
            dp[dt.v][ns]=nt;
            Q.push((Data){dt.v,ns,nt});
        }
        // trans
       
        for(auto e:E[dt.v]){
            ns=dt.s-e.a;
            nt=curt+e.b;//?dt.t+e.b
            if(ns>=0 and dp[e.to][ns]>nt){
                dp[e.to][ns]=nt;
                Q.push((Data){e.to,ns,nt});
            }
        }
    }
    rep(i,2,n){
        ll ans=INF;
        rep(j,0,MAXS){
            ans=min(ans,dp[i][j]);
            
        }
        cout<<ans<<endl;
    }
}
/* 
dp[i][j] min time takes from 1 to node i, have j coin with me.
dp[i][j]=dp[k][j-cost]
wr: 最后的更新出错, INF太小
Q: 更新时 用当前的状态dt.t or 储存的最优状态dp  我倾向于用dt，感觉更好理解
 */