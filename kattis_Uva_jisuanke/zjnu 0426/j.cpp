#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
vector<string> ans;
void turn(int flag,int del,string cur,int p){
    {
        rep(i,1,del){
            char c=cur[p];
            c+=flag?1:-1;
            if(c>'9')c='0';
            if(c<'0')c='9';
            cur[p]=c;
            ans.push_back(cur);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s[2];cin>>s[0]>>s[1];
    ans.push_back(s[0]);
    for(int i=4;i>=0;i--)if(i!=2){
        
        int flag=(s[1][i]>s[0][i]);
        int rev=0;
        int del=abs(s[1][i]-s[0][i]);
        if(del==0)continue;
        if(del>5)flag=!flag,rev=1;
        turn(flag,rev?10-del:rev,ans.back(),i);
    }
    cout<<ans.size()<<endl;
    for(auto t:ans)cout<<t<<endl;
}