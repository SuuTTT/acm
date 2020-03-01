#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int dp[11005][2005];
const int INF=1100005;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    int l1=s1.size()-1,l2=s2.size()-1;
    int tmp=0;
    int num=0;
    rep(i,0,l1){
        if(s1[i]>='0'&&s1[i]<='9'){
            num++;
            tmp=s1[i]-'0';
            if(tmp)s1[i]='*';
            else s1.erase(s1.begin()+i),l1--,i--;
            rep(j,1,tmp-1)s1.insert(i,"*"),l1++;
        }
    }
    rep(i,0,l2){
        if(s2[i]>='0'&&s2[i]<='9'){
            num++;
            tmp=s2[i]-'0';
            if(tmp)s2[i]='*';
            else s2.erase(s2.begin()+i),l2--,i--;
            rep(j,1,tmp-1)s2.insert(i,"*"),l2++;
        }
    }
    l1++,l2++;
    rep(i,0,l1)rep(j,0,l2)dp[i][j]=INF;
    rep(i,0,l1)dp[i][0]=i;
    rep(j,0,l2)dp[0][j]=j;
    dp[0][0]=0;
    rep(i,1,l1)rep(j,1,l2){
        dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
        dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        if(s1[i-1]==s2[j-1]||s1[i-1]=='*'||s2[j-1]=='*')dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
        
    }
    //debug(s1),debug(s2);
    //debug(dp[0][0]);debug(dp[1][0]);debug(dp[0][1]);debug(dp[1][1]);
    cout<<dp[l1][l2]+num<<endl;
}
/* 
101a
1011
2e2c1d0a1101
2e2c1d0a111
beer5ing
4drinking
 */