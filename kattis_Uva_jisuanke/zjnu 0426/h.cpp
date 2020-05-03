#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string s[4];
int flag[4][maxn];//flag[1][i] 12 2转右i格合法? 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	rep(i,1,3)cin>>s[i];int n=s[1].length();
	rep(i,1,3)rep(j,0,n)flag[i][j]=1;
	rep(i,0,n-1)rep(j,0,n-1){
		if(s[1][j]==s[2][(j+i)%n])flag[1][i]=0;
		if(s[1][j]==s[3][(j+i)%n])flag[2][i]=0;
		if(s[2][j]==s[3][(j+i)%n])flag[3][i]=0;
	}
	int ans=maxn;
	rep(i,0,n-1)rep(j,0,n-1){
		if(!flag[1][i])continue;
		if(!flag[2][j])continue;
		if(!flag[3][(j-i+n)%n])continue;
		ans=min(ans,min(i,n-i)+min(j,n-j));
		ans=min(ans,max(i,j));
		ans=min(ans,max(n-i,n-j));
	}
	cout<<(ans==maxn?-1:ans)<<endl;
}
/* 

ABC
ABC
ABC
 */