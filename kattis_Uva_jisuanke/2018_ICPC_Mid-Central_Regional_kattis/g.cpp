#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

void rotate(char &c){
    c++;
    if(c=='G')c='A';
}
string change(string s,int x){
    if(s[x]=='A'){
        if(x-1>=0)rotate(s[x-1]);
        if(x+1<=7)rotate(s[x+1]);
    }else if(s[x]=='B'){
        if(x!=0 && x!=7)s[x+1]=s[x-1];
    }else if(s[x]=='C'){
        x++;
        x=9-x;
        x--;
        rotate(s[x]);
    }else if(s[x]=='D'){
        if(x==0 || x==7){
            ;
        }else if(x<=3){
            rep(i,0,x-1)rotate(s[i]);
        }else{
            rep(i,x+1,7)rotate(s[i]);
        }
    }else if(s[x]=='E'){
        if(x==0 || x==7){
            ;
        }else if(x<=3){
            rotate(s[0]);rotate(s[2*x]);
        }else{
            rotate(s[7]);rotate(s[2*x-7]);
        }
    }else if(s[x]=='F'){
        x++;
        if(x&1)rotate(s[(x+9)/2-1]);
        else rotate(s[x/2-1]);
    }
    return s;
}
unordered_map<string,int> mp;
queue<string> q;
ll bfs(string S,string T){
    while(!q.empty())q.pop();
    mp.clear();
    q.push(S);mp[S]=0;
    string u,v;
    while(!q.empty()){
        u=q.front();
        q.pop();
        if(u==T)return mp[u];
        rep(i,0,7){
            v=change(u,i);
            if(mp.find(v)==mp.end()){
                mp[v]=mp[u]+1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string S,T;
    while(cin>>S>>T){
        cout<<bfs(S,T)<<endl;
    }
    return 0;
}
/*

*///