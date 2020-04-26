#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string mp[8];
struct node{
    int r,c;
    int dr,dc;
    int t;
    string path;
    node(int r,int c,int dr,int dc,int t, string p):r(r),c(c),dr(dr),dc(dc),t(t),path(p){};
    bool operator< (const  node& a)const{return t>a.t;}//小的在前面
    void print(){cout<<r<<' '<<c<<' '<<dr<<' '<<dc<<' '<<t<<' '<<path<<endl;}
};
set<node> st;
int vis[8][8][8][8];
bool Vis(node x){
    return vis[x.r][x.c][x.dr+1][x.dc+1];
}
bool setVis(node x){
    return vis[x.r][x.c][x.dr+1][x.dc+1]=1;
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rep(i,0,7)cin>>mp[i];
    debug(1);
    node start(7,0,0,1,0,"");
    priority_queue<node> Q;
    Q.push(start);
    //for(auto t:start.st)cout<<t.first;
    while(!Q.empty()){
        node now=Q.top();
        Q.pop();
        //now.print();
        if(mp[now.r][now.c]=='D'){
            cout<<now.path<<endl;
            return 0;
        }
        node cur=now;
        
        //L
        cur=now;swap(cur.dr,cur.dc);cur.dr=-cur.dr;
        if(!Vis(cur)){
            cur.path+='L';
            cur.t=now.t+1;
            Q.push(cur);
            setVis(cur);
        }
        
        //R
        cur=now;swap(cur.dr,cur.dc);cur.dc=-cur.dc;
        if(!Vis(cur)){
            cur.path+='R';
            cur.t=now.t+1;
            Q.push(cur);
            setVis(cur);
        }
        cur=now;int rr=now.r+now.dr,cc=now.c+now.dc;
        if(now.r+now.dr<8&&now.r+now.dr>=0&&now.c+now.dc<8&&now.c+now.dc>=0&&vis[rr][cc][now.dr+1][now.dc+1]==0){
             //F
            if(mp[now.r+now.dr][now.c+now.dc]=='I'){
                cur=now;
                cur.r=now.r+now.dr;
                cur.c=now.c+now.dc;
                cur.t=now.t+2;
                cur.path+="XF";
                Q.push(cur);
                setVis(cur);
            }else if(mp[now.r+now.dr][now.c+now.dc]!='C'){
                cur=now;
                cur.r=now.r+now.dr;
                cur.c=now.c+now.dc;
                cur.t=now.t+1;
                cur.path+='F';
                Q.push(cur);
                setVis(cur);
            }
            
        }
        

        
    }
    cout<<"no solution"<<endl;
}
/* 
用priorityQ 改变搜索顺序
........
........
........
...CC...
..C.DC..
.C..C...
C.IC....
T.C.....
 */