
#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
vector<int> g[6];
int L[10],du[10];
bool toposort(){
    fill(du,du+10,0);
    for(int i='A';i<='E';i++)
        for(auto t:g[i]) du[t]++;
    int tot=0;
    queue<int> Q;
    for(int i='A';i<='E';i++)
        if(!du[i])Q.push(i);
    while(!Q.empty()){
        int x=Q.front();Q.pop();
        L[tot++]=x;
        for(auto t:g[x]){
            du[t]--;
            if(!du[t])
                Q.push(t);
        }
    }
    //debug(tot);
    if(tot == 5)return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rep(i,1,5){
        string s;
        cin>>s;
        s[1]=='<'?g[s[0]].push_back(s[2]):g[s[2]].push_back(s[0]);
    }
    if(toposort())rep(i,0,4)cout<<(char)L[i];
    else cout<<"impossible";
    
}
/* 
D>B
A>D
E<C
A>B
B>C
*/