#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<(x)<<endl
const int maxn=(int)1e6+5;
int n,m,h;
vector< pair<int,int> > ans[105]; //第i层的答案
bitset<105> f[105],l[105];
void print(){
    
    rep(i,0,n-1)for(auto p:ans[i]){
        //cout<<i<<' '<<p.first<<' '<<p.second<<endl;
        printf("%d %d %d\n",i,p.first,p.second);
    }
    rep(i,0,n-1)ans[i].clear();
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>h;
    rep(i,0,n-1)cin>>f[i];
    rep(i,0,n-1)cin>>l[i];
    int mx=0,mn=0;
    rep(i,0,n-1){
        vector<int> y,z;
        rep(j,0,m-1)if(f[i][m-1-j])y.push_back(j);//bitset b[i]是从右往左的。
        rep(j,0,h-1)if(l[i][h-1-j])z.push_back(j);
        mx+=y.size()*z.size();
        if(y.size()&&(!z.size())||z.size()&&(!y.size())){cout<<-1<<endl;return 0;}
        for(auto yy:y)for(auto zz:z)
        ans[i].push_back({yy,zz});
    }
    cout<<mx<<endl;
    print();
    rep(i,0,n-1){
        vector<int> y,z;
        rep(j,0,m-1)if(f[i][m-1-j])y.push_back(j);
        rep(j,0,h-1)if(l[i][h-1-j])z.push_back(j);
        mn+=max(y.size(),z.size());
        if(y.size()>=z.size()){
            int d=y.size()-z.size();
            rep(j,0,d-1)ans[i].push_back({y[j],z[0]});
            rep(j,0,z.size()-1)ans[i].push_back({y[j+d],z[j]});
        }else{
            int d=-y.size()+z.size();
            rep(j,0,d-1)ans[i].push_back({y[0],z[j]});
            rep(j,0,y.size()-1)ans[i].push_back({y[j],z[j+d]});
        }
        
    }
    cout<<mn<<endl;
    print();
}
/* 

f[i][j]=1 说明 (i,j,_) 这条线(0,0,1)方向上，至少有一个
l[i][j]=1 说明 (i,_,j) 这条线(0,1,0)方向上，至少有一个

可以把x坐标分离，一层一层考虑。

画一下从上往下看 俯视图up[i][j]

h
/_
|  m
n

    *?*?*
1   ?????
    *?*?*
1   ?????
    *?*?*
     1 1 

max case is obvious, put a cube on every intersect
min case ana: l,f 哪个1多就是哪个：多的每个放一个行block，顺便填到少的那边即可。
字典序最小: 
先x最小：从上往下
然后y最小：从左到右，
最后z：从前到后。

f1[i]=正视图第i层有几个1
l1[i]=
f1[i]>l1[i]: 先全放第一排，然后一个一个往后放
实现：将每一层的交点预处理(m,h) 排序
f1[i]==l1[i]:每个m取一个
f1[i]>l1[i]:先取第一行，然后和后面一样
f1[i]<l1[i]:先取第一列，然后和后面一样

TLE :1e6 的输出 满了10倍
 */