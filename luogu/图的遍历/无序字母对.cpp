#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
/* 
分析：题意等价于给n条边，找一个有n+1节点的链,多届取字典序最小。
单一解只要从入度为0的点遍历即可。
这里多解当且仅当形成一个环，一共2500个点，可以直接排序得到。
wa：fix了aa的样例，不知道哪里错了。

代码：有的循环必须要dfs，而且码量一样的。

正解是欧拉回路版题
 */
vector<int> E[maxn];
int in[maxn];
int vis[maxn];
int f[maxn];
set<int> st;
string s;
void dfs(int now){
    vis[now]=1;
    for(auto t:E[now]){
        if(vis[t])continue;
        s.push_back((char)t);
        if(f[t])s.push_back((char)t);
        dfs(t);
    }
}

int main(){
    int n;
    cin>>n;
    rep(i,1,n){
        string s;
        cin>>s;
        int x=s[0],y=s[1];
        E[x].push_back(y);
        E[y].push_back(x);
        in[x]++;in[y]++;
        if(x==y)f[x]=1;
        st.insert(x);st.insert(y);
    }
    int now=0;
   for(auto x:st)if(in[x]==1){now=x;break;}
    if(now){
        vis[now]=1;
        s.push_back((char)now);
        if(f[now])s.push_back((char)now);
        dfs(now);
        string ss=s;
        reverse(s.begin(),s.end());
        s=min(s,ss);
        if(s.size()==n+1)cout<<s<<endl;
        else cout<<"No Solution"<<endl;

    }
    else{
        now=*st.begin();
        vis[now]=1;
        s.push_back((char)now);
        if(f[now])s.push_back((char)now);
        dfs(now);
        s.push_back(s[0]);
        cout<<s;
    }
}
/* 
4
aZ
tZ
Xt
aX
 */