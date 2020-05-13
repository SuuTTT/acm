#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string s[4];

int main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;while(T--){
		double b,p;
		cin>>b>>p;
		double t1=p/b;double t0=(p)/(b+1),t2=(p)/(b-1);
		printf("%.5lf %.5lf %.5lf\n",60./t2,60./t1,60./t0);
	}
}
/* 

ABC
ABC
ABC
 */