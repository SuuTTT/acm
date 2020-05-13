#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int l,flag;
int ans[maxn],t[maxn],num[maxn];
bool ok(){
    rep(i,0,l)t[i]=0;
    rep(i,0,l/2)rep(j,0,l/2){
        t[i+j]+=ans[i]*ans[j];
    }
    rep(i,0,l-1)if(t[i]%10!=num[i])return 0;
    return 1;
}
bool dfs(int p){
    if(p==l/2+1){
        if(ok()){
            flag=1;return 1;
        }
        return 0;
    }
    rep(i,0,9){
        ans[p]=i;
        int tmp=0;
        rep(j,0,p)tmp+=ans[j]*ans[p-j];
        //debug(i),debug(tmp);
        if(tmp%10==num[p])if (dfs(p+1))return 1;
    }
    return 0;
}
int main(){
    string s;
    cin>>s;l=s.length();
    rep(i,1,l)num[i-1]=s[i-1]-'0';
    dfs(0);
    if(l%2==0)flag=0;
    if(flag==0){puts("-1");}
    else {
        
        rep(i,0,l/2)cout<<ans[i];
        cout<<endl;
    }
}
/* 
123476544
445674321
1000000000000000000000000
 */