#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
vector<int> num[maxn],E[maxn];
map<int,int> mp;
int fa[maxn],cnt;
struct node{
    int x,y,z;
};
vector<node>ans; 
 int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
void un(int i,int t,int v){
    int eu=find(i),ev=find(t);
    if(eu==ev)return;
    fa[ev]=eu;
    ans.push_back({i,t,v});
    ++cnt;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n){
        int m;cin>>m;
        rep(j,1,m){
            int x;
            cin>>x;
            num[i].push_back(x);
            if(mp.count(x));
            else{mp[x]=i;}
        }
    }
    int flag=0;
    rep(i,1,n)fa[i]=i;
    rep(i,1,n)for(auto t:num[i]){
        /* E[i].push_back(mp[t]);
        E[mp[t]].push_back(i); */
       un(i,mp[t],t);
       if(cnt==n-1){flag=1;break;}
       un(mp[t],i,t);
        if(cnt==n-1){flag=1;break;}
    }
    if(flag){
        for(auto t:ans){
            cout<<t.x<<' '<<t.y<<' '<<t.z<<endl;
        }
    }else{
        cout<<"impossible"<<endl;
    }
}
/* 
6
2 17 10
2 5 10
2 10 22
3 17 22 9
2 17 8
3 9 22 16

 */