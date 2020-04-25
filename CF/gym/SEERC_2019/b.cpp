#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)500+1;
typedef long long ll;
ll dp[2][maxn][maxn];
ll inf=(ll)1e18+8;
int n,s1,s2;
struct quest
{
    /* data */
    int x1,x2;
    ll t1,t2;
    bool operator<(const quest &a)const {
        return x1<a.x1;
    }
}q[maxn];
void init(int x){
    rep(j,0,s1)rep(k,0,s2)dp[x][j][k]=inf;
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>s1>>s2;
    rep(i,1,n){
        cin>>q[i].x1>>q[i].t1>>q[i].x2>>q[i].t2;
    }
    sort(q+1,q+1+n);
    rep(i,0,1)rep(j,0,s1)rep(k,0,s2)dp[i][j][k]=inf;
    dp[1][0][0]=0;
    
    rep(i,1,n){
        int cur=i&1,nxt=cur^1;
        rep(j,0,s1)rep(k,0,s2){
            
            if(dp[cur][j][k]==inf)continue;
            
            dp[nxt][j][k]=min(dp[nxt][j][k],dp[cur][j][k]);
            //debug(i),debug(j),debug(k),debug(dp[cur][j][k]);
            if(j<s1){
                int _j=j,_k=k;
                _j+=q[i].x1;
                if(_j>s1){
                    _k+=_j-s1;
                    _j=s1;
                }
                dp[nxt][_j][min(s2,_k)]=min(dp[nxt][_j][min(s2,_k)],dp[cur][j][k]+q[i].t1);
            }
            dp[nxt][j][min(s2,k+q[i].x2)]=min(dp[nxt][j][min(s2,k+q[i].x2)],dp[cur][j][k]+q[i].t2);
        }
        init(cur);
    }

    cout<<(dp[!(n&1)][s1][s2]==inf?-1:dp[!(n&1)][s1][s2])<<endl;
   
}
/* 
262144K
125000000*16bit/8/1024=244140
做任务升级，每个任务有经验值x和花费时间t，lv1,lv2的x,t可能不同。
lv1需要s1经验, lv2需要s2。升级时经验溢出会计算入下一级。
求最快升满2级的时间。


ana 背包，
1.x1最大的最后做不会更坏
2.转移
ana:
转移有两种写法，当前状态到别的。 当前从别的
4 20 20
40 1000 20 20
6 6 5 5
10 10 1 1
10 10 1 1

2 5 5
5 1 5 1
5 1 5 1

2 5 5
2 2 1 1 
3 3 2 2

2 100 100
100 100 10 10
101 11 100 10


 */