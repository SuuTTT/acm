#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string s[4];
char mp[105][105];
int main(){
	int n;
	cin>>n;
	rep(i,1,n){
		string s;cin>>s;
		int len=s.size();
		int k=0;
		rep(i,1,100){
			if(i*i>=len){k=i;break;}
		}
		int cnt=0;
		rep(i,1,k)rep(j,1,k){
			mp[i][j]=cnt<len?s[cnt]:'*';
			cnt++;
		}
		string ans;
		rep(j,1,k)for(int i=k;i>0;i--)if(mp[i][j]!='*'){
			ans+=mp[i][j];
		}
		cout<<ans<<endl;
	}
}
/* 
2
iloveyoutooJill
TheContestisOver
 */