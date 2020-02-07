#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e3+5;
const int inf=(int)1e9;
typedef  pair<int,int>  pii;
#define  vtx first
#define  val second
vector<pii> E[maxn],reE[maxn];
int d[maxn],red[maxn];
/* 
正反建边跑两遍

评论里说有矩阵转置的做法？？
 */
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,x;
    cin>>n>>m>>x;
    rep(i,1,m){
        int x,y,z;
        cin>>x>>y>>z;
        E[x].push_back({y,z});
        reE[y].push_back({x,z});
    }
    rep(i,1,n)d[i]=red[i]=inf;
    priority_queue<pii > Q;
    Q.push({0,x});d[x]=0;
    while(!Q.empty()){
        pii now=Q.top();
        Q.pop();
        vector<pii>& vv=E[now.second];
        for(int i=0;i<vv.size();i++){
            if(d[vv[i].vtx]>d[now.second]+vv[i].val){
              d[vv[i].vtx]=d[now.second]+vv[i].val;
              Q.push({-d[vv[i].vtx],vv[i].vtx}); 
            }
        }
    }
    Q.push({0,x});red[x]=0;
    while(!Q.empty()){
        pii now=Q.top();
        Q.pop();
        vector<pii>& vv=reE[now.second];
        for(int i=0;i<vv.size();i++){
            if(red[vv[i].vtx]>red[now.second]+vv[i].val){
              red[vv[i].vtx]=red[now.second]+vv[i].val;
              Q.push({-red[vv[i].vtx],vv[i].vtx}); 
            }
        }
    }
    int ans=0;
    rep(i,1,n){
        if(d[i]==inf)d[i]=-1;
        if(red[i]==inf)red[i]=-1;
        //debug(i),debug(d[i]),debug(red[i]);
    }
    rep(i,1,n){
        ans=max(ans,d[i]+red[i]);
    }
    cout<<ans<<endl;
}

/* 
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3 */