#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string s1,s2;
unordered_set<string> vis;
void rot(char &c){
    c++;
    if(c>'F')c='A';
    //return c;
}
bool ok(int p){
    return p<=8&&p>=1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s1>>s2;
    queue< pair<string,int> >Q;
    Q.push({s1,0} );
    vis.insert(s1);
    while(!Q.empty()){
        string cur=Q.front().first;
        //debug(cur);
        int ans=Q.front().second;
        if(cur==s2){
            cout<<ans<<endl;
            break;
        }
        Q.pop();
        string tmp='a'+cur;
        rep(i,1,8){
            cur=tmp;
            if(cur[i]=='A'){
                if(ok(i-1))rot(cur[i-1]);
                if(ok(i+1))rot(cur[i+1]);
            }
            if(cur[i]=='B'){
                if(i==8||i==1)continue;
                else cur[i+1]=cur[i-1];
            }
            if(cur[i]=='C'){
                rot(cur[9-i]);
            }
            if(cur[i]=='D'){
                if(i<=4){
                    rep(j,1,i-1)rot(cur[j]);
                }else rep(j,i+1,8)rot(cur[j]);
            }
            if(cur[i]=='E'){
                if(i==1||i==8)continue;
                if(i<=4){
                    int y=i-1;
                    rot(cur[i-y]);
                    rot(cur[i+y]);
                }else {
                    int y=8-i;
                    rot(cur[i+y]);
                    rot(cur[i-y]);
                }
            }
            if(cur[i]=='F'){
                if(i%2==1)rot(cur[(i+9)/2]);
                else rot(cur[i/2]);
            }
            cur=cur.substr(1,8);
            //debug(cur);
           if(vis.find(cur)!=vis.end())continue;
           vis.insert(cur);
           Q.push({cur,ans+1});
        }
    }
}
/* 
ABCDEFCD
BCEDEFCD
 */