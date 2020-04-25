#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int cnt[2][256];
string s[2];
int n[2];
bool isnum(char c){
	return c>='0'&&c<='9';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s[0]>>n[0]>>s[1];
	rep(x,0,1){
		for(int i=0,l=s[x].length();i<l;i++)if(!isnum(s[x][i])){
			char c=s[x][i];
			int num=0;
			i++;
			while(isnum(s[x][i]))num*=10,num+=(s[x][i]-'0'),i++;
			i--;
			if(num==0)num=1;
			cnt[x][c]+=num;
			//debug(num),debug(c);
		}
	}
	int ans=1e9;
	rep(i,'A','Z')if(cnt[1][i]){
		ans=min(ans,cnt[0][i]*n[0]/cnt[1][i]);
	}
	cout<<(ans==1e9?0:ans)<<endl;
}
/* 
没定义变量&错
题目忘了
H 1
H
 */