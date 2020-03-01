#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[10];
int ok(int x){
	rep(i,0,9)a[i]=0;
	int xx=x,p=0;
	while(xx){a[xx%10]++,xx/=10;}
	//debug(a[1]);
	if(a[0]==1)return 0;
	rep(i,0,9)if(a[i]){
		if(a[i]>1)return 0;
		if(x%i)return 0;
		//debug(x%a[i]),debug(i);
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int l,h;
	cin>>l>>h;
	int ans=0;
	rep(i,l,h){
		//debug(i);
		if(ok(i))ans++;
	}
	cout<<ans<<endl;
}
/* 
123456 123456
123864 123865
123456≤L<H≤987654
 */