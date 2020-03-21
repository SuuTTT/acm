#include<bits/stdc++.h>
using namespace std;
#define int long long
string str;
int dp[666][666];//dp[i][j] 高到低第i位,j个0
int a[666];int k;
int dfs(int pos,int state,bool lead/*前导零*/,bool limit/*数位上界变量*/){
	if(pos==-1) return k==state;
	if(!limit && !lead && dp[pos][state]!=-1) return dp[pos][state];
	int up=limit?a[pos]:9;
	int ans=0;
	for(int i=0;i<=up;i++){
			ans+=dfs(pos-1,state+( (i == 0?0:1)),i==0&&lead,limit&& i==a[pos]);
	
	}
	if(!limit && !lead) dp[pos][state]=ans;
	return ans;
}
signed main(){
	memset(dp,-1,sizeof(dp));
	cin>>str>>k;int cnt=0;
	for(int i=str.size()-1;i>=0;i--) a[cnt++]=(str[i]-'0');
	cout<<dfs(cnt-1,0,true,true);
	return 0;
}
