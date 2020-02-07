#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
//不断删除入度为0 的点。
vector<int> g[maxn];
int du[maxn],n,m,L[maxn];
bool toposort(){
    fill(du,du+maxn,0);
    for(int i=0;i<n;i++)
        for(auto t:g[i]) du[t]++;
    int tot=0;
    queue<int> Q;
    for(int i=0;i<n;i++)
        if(!du[i])Q.push(i);
    while(!Q.empty()){
        int x=Q.front();Q.pop();
        L[tot++]=x;
        for(auto t:g[x]){
            du[t]--;
            if(!du[t])
                Q.push(t);
        }
    }
    if(tot == n)return 1;
    return 0;
}
int main(){

}