#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<(x)<<endl
const int maxn=(int)1e6+5;
typedef vector<vector<int> > v3;
bool ok(int x){
    return x>=0 and x<=2;
}
void stamp(int x,int y,v3& a){
    rep(i,-1,1)rep(j,-1,1)if(abs(i)+abs(j)!=2){
        int dx=x+i,dy=y+j;
        if(ok(dx)&&ok(dy))a[dx][dy]=!a[dx][dy];
    }
}
void print(v3 a){
    rep(i,0,2){
        rep(j,0,2)cout<<a[i][j];
        cout<<endl;
    }
}
string mp[3];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<int> a(1,2),b(2,2);
    a.push_back(-1);
    debug(a<b);
    
    int t;cin>>t;
    
    while(t--){
        rep(i,0,2)cin>>mp[i];
        v3 g(3,vector<int>(3,0)),s(3,vector<int>(3,0));
        rep(i,0,2)rep(j,0,2)g[i][j]=(mp[i][j]=='*'?1:0);
        
        //rep(i,0,2)rep(j,0,2)debug(g[i][j]);
        queue<pair<v3,int> > Q;set<v3> vis;
        Q.push({s,0} );
        vis.insert(s);
        
        while(!Q.empty()){
            auto cur=Q.front().first;
            auto cnt=Q.front().second;
            //print(cur);cout<<endl;
            auto backup=cur;
            if(cur==g){
                
                cout<<cnt<<endl;
                break;
            }
            rep(i,0,2)rep(j,0,2){
                cur=backup;
                stamp(i,j,cur);
                if(vis.count(cur))continue;
                Q.push({cur,cnt+1});
                vis.insert(cur);
            }
            Q.pop();
        }

    }
}
/* 
vector 可以比较吗？ c++.com: behaves as if using algorithm lexicographical_compare
 */