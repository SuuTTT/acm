#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int w,h,ans;
inline int id(char c){
    return (c-'A'+1)*1000;
}
int de(string s){
    int ret=id(s.back());
    s.pop_back();
    int cur=0;
    for(auto c:s){
        cur*=10;
        cur+=c-'0';
    }
    return ret+cur;
}
inline int idx(int i,int j){
    return (i-1)*w+j;
}
/*
 int f[maxn];
int find(int x){return f[x]==x?x:f[x]=find(x);}
int un(int x,y){
    x=find(x),y=find(y);
    if(x!=y)f[x]=y;
} */
vector<int> E[maxn];
void add(int x,int y){
    E[x].push_back(y);
    E[y].push_back(x);
}
void dfs(int u,int fa){
   // debug(u),debug(fa),getchar();
    if(u!=fa&&E[u].size()==1)ans=u;
    for(auto t:E[u]){
        if(t!=fa)dfs(t,u);
    }
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int kase=0;
    while(cin>>h>>w){
        if(h==w&&h==0)break;
        //rep(i,1,h*n+8000)f[i]=i;
        rep(i,1,h*w+8000)E[i].clear();//T?
        int x;
        while(cin>>x){
            if(x==0)break;
            int i=x/w+1;
            int j=(x-1)%w+1;
            
            string s;
            getline(cin,s);
            stringstream ss;
            ss<<s;
            while(ss>>s){
                //debug(s);
                //un(id(s[0])+idx,id(s[1])+idx);
                add(id(s[0])+x,id(s[1])+x);
            }

        }
        rep(i,1,h-1)rep(j,1,w-1){
            //add(idx(i,j)+0,idx(i-1,j)+6000);add(idx(i,j)+1000,idx(i-1,j)+5000);
            add(idx(i,j)+6000,idx(i+1,j)+1000);add(idx(i,j)+5000,idx(i+1,j)+2000);
           // add(idx(i,j)+8000,idx(i,j-1)+3000);add(idx(i,j)+7000,idx(i,j-1)+4000);
            add(idx(i,j)+3000,idx(i,j+1)+8000);add(idx(i,j)+4000,idx(i,j+1)+7000);
        }
        rep(i,1,h-1)rep(j,w,w){
            add(idx(i,j)+6000,idx(i+1,j)+1000);add(idx(i,j)+5000,idx(i+1,j)+2000);
        }
        rep(i,h,h)rep(j,1,w-1){
            add(idx(i,j)+3000,idx(i,j+1)+8000);add(idx(i,j)+4000,idx(i,j+1)+7000);
        }
        string s;
        getchar();getline(cin,s);
        stringstream ss;
        ss<<s;
        cout<<"Board "<<++kase<<":"<<endl;
        while(ss>>s){
            int now=de(s);
            //debug(s),debug(now);
            int fa=0;
            //for(auto t:E[now])if(E[t].size()==1)fa=t;

            dfs(now,now);
            cout<<s<<" is connected to "<<ans%1000<<(char)('A'+ans/1000-1)<<endl;
        }
        cout<<endl;
    }
}

/* 
2 3
4 AG BF
3 AF EH
6 AC BF
1 AH CE DF
2 AG CH
0
1A 2A 3A 4F

 */