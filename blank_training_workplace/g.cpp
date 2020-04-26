#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string s1,s2;
unordered_set<string> vis;
char rot(char &c){
    c++;
    if(c>'F')c='A';
    //return c;
}
bool ok(int p){
    return p<8&&p>=0;
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
        string tmp=cur;
        rep(i,1,8){
            cur=tmp;
            if(cur[i-1]=='A'){
                if(ok(i-2))rot(cur[i-2]);
                if(ok(i))rot(cur[i]);
            }
            if(cur[i-1]=='B'){
                if(i==8||i==1)continue;
                else cur[i]=cur[i-2];
            }
            if(cur[i-1]=='C'){
                
                rot(cur[7-(i-1)]);
            }
            if(cur[i-1]=='D'){
                if(i<=4){
                    rep(j,0,i-2)rot(cur[j]);
                }else rep(j,i,7)rot(cur[j]);
            }
            if(cur[i-1]=='E'){
                if(i==1||i==8)continue;
                if(i<=4){
                    int y=i-1;
                    rot(cur[i-1-y]);
                    rot(cur[i-1+y]);
                }else {
                    int y=8-i;
                    rot(cur[i+y-1]);
                    rot(cur[i-y-1]);
                }
            }
            if(cur[i-1]=='F'){
                if(i%2==1)rot(cur[(i+9)/2-1]);
                else rot(cur[i/2-1]);
            }
           if(vis.count(cur))continue;
           vis.insert(cur);
           Q.push({cur,ans+1});
        }
    }
}
/* 
ABCDEFCD
BCEDEFCD
 */