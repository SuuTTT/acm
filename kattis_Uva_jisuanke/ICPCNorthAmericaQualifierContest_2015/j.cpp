#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define per(i,j,k) for(int i = (int)j;i >= (int)k;i --)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define pb push_back

typedef double db;
typedef long long ll;
const int MAXN = (int)2e3+7;
const int INF = (int)0x3f3f3f3f;
int n;
struct node{
    int to,next;
}e[2009];
int head[40],cnt;
void add(int u,int v){
    cnt++;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
map<string,int>mp;
string name[40],x,y;
char str[2009];
int tot;
int s,t;
vector<string>ans;
int flag=0;
int vis[40];
int dfs(int now){
    vis[now]=1;
    if(flag)return 0;
    if(now==t){
        ans.push_back(name[now]);
        flag=1;
        return 1;
    }
    for(int i=head[now];i;i=e[i].next){
        int to=e[i].to;
        if(vis[to])continue;
        if(dfs(to)){
            ans.push_back(name[now]);
            return 1;
        }
    }
    return 0;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    cin.getline(str,2000);
    for(int i=0;i<n;i++){
        cin.getline(str,2000);
        x="";
        int j=0;
        while(str[j]!='\0'&&str[j]!=' '){
            x+=str[j];
            j++;
        }
        if(!mp[x]){mp[x]=++tot;name[tot]=x;}
        j++;
        y="";
        while(str[j]!='\0'){
            if(str[j]==' '){
                if(!mp[y]){mp[y]=++tot;name[tot]=y;}
                add(mp[x],mp[y]);
                add(mp[y],mp[x]);
                y="";
            }
            else{
                y+=str[j];
            }
            j++;
        }
        if(!mp[y]){mp[y]=++tot;name[tot]=y;}
        add(mp[x],mp[y]);
        add(mp[y],mp[x]);
    }
    cin>>x>>y;
    s=mp[x];t=mp[y];
    if(s==0||t==0)flag=1;
    if(dfs(s)){
        for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
        cout<<endl;
    }
    else cout<<"no route found"<<endl;
}
/*
一个图，起点终点，输出一条路径
*/