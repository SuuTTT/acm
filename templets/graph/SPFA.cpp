#include<bits/stdc++.h>
//SJTU 
//set n,m,src
//no negtive cycle

const int maxn=1000;

int n,m,src;
vector<pair<int,int> > g[maxn+10];
int dist[maxn+10];
bool inQ[maxn+10];
queue<int> que;

void spfa(){
    memset(dist, 63,sizeof(dist));
    dist[src]=0;
    while(!que.empty())que.pop();
    que.push(src);
    inQ[src]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(aut v:g[u])
            if(dist[u]+v.second<dist[v.first]){
                dist[v.first]=dist[u]+v.second;
                 if(!inQ[v]){
                     inQ[v.first]=1;
                     que.push(v);
                 }
            }
        inq[u]=0;
    }
}
