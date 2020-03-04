#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	rep(t,1,n){
		printf("Data set #%d: \n",t);
		int a[3];
		rep(i,0,2)cin>>a[i];
		printf("   Original order: %d %d %d\n",a[0],a[1],a[2]);
		sort(a,a+3);
		printf("   Smallest to largest: %d %d %d\n\n",a[0],a[1],a[2]);
	}
}

/* 
2
10 7 5
4 30 20
Data set #1: 
   Original order: 10 7 5 
   Smallest to largest: 5 7 10 

Data set #2: 
   Original order: 4 30 20 
   Smallest to largest: 4 20 30

 */