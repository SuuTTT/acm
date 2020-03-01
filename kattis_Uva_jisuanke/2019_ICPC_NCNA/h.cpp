#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
vector<int> b;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	rep(i,1,n){
		string s;
		cin>>s;
		if(s[0]=='Z')b.push_back(1);else b.push_back(0);
	}
	int cnt=0;
	//rep(i,0,n-1)debug(b[i]);
	while(1){
		int flag=1;
		rep(i,0,n-1)flag&=b[i];
		if(flag)break;
		cnt++;
		for(int i=n-1;i>=0;i--){
			if(b[i]==0){
				b[i]=1;
				rep(j,i+1,n-1)if(b[j])b[j]=0;
				break;
			}
		}
	}
	cout<<cnt<<endl;
}
/* 
5
Z
O
Z
O
Z
20
o
o
o
o
o
o
o
o
o
o
o
o
o
o
o
o
o
o
o
 */