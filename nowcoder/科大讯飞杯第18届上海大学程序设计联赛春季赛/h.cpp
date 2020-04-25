#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e5+5;
string s;
int cnt[10],ans[10],k;
int flag[4][maxn];//flag[1][i] 12 2转右i格合法? 
int m1[3]={7,4,1};
int m2[3]={8,5,2};
int cur=0;//sum(ans[])
int take(int m,int x){//拿了m个x,拿满k个返回1
	int tmp=0;
	tmp=min(m,k-cur);
	cur+=tmp;
	ans[x]+=tmp;
	cnt[x]-=tmp;
	if(cur==k)return 1;
	else return 0;
}
int mx(int m[],int no){
	rep(i,0,3){
		if(cnt[m[i]]&&m[i]!=no)return m[i]; 
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		//string s;int k;
		//scanf("%s",&s);
		cin>>s>>k;
		rep(i,0,9)cnt[i]=0,ans[i]=0;
		for(auto c:s)cnt[c-'0']++;
		cur=0;
		for(int i=9;i>=0;i--){
			if(i%3==0){
				if(take(cnt[i],i))break;
			}else if(i%3==1){

				int mxn=cnt[i]-cnt[i]%3;
				if(take(mxn,i))break;	
				if(cnt[i]==1){
					if(k-cur==1)continue;
					if(k-cur==2){
						int m=mx(m2,i);if(m==0)continue;
						take(1,m);
						if(take(1,i))break;
					}else if(k-cur>=3){
						int mx1=mx(m1,i),mx2=mx(m2,i);
							if(mx1>mx2){
								take(1,mx1);
								mx1=mx(m1,i);
								take(1,mx1);
								if(take(1,i))break;
							}else{
								if(mx2==0)continue;
								take(1,mx2);
								if(take(1,i))break;
							}
					}
					
				}else if(cnt[i]==2){
					if(k-cur==3){
						int m=mx(m1,i);
						if(m==0)continue;
						take(2,i);
						if(take(1,m))break;
					}else if(k-cur>3){
							int mx1=mx(m1,i),mx2=mx(m2,i);
							if(mx1>mx2){
								take(1,mx1);
								mx1=mx(m1,i);
								take(1,mx1);
								if(take(2,i))break;
							}else{
								if(mx2==0)continue;
								take(1,mx2);
								if(take(2,i))break;
							}
						}
					}
				}else if(i%3==2){

				int mxn=cnt[i]-cnt[i]%3;
				if(take(mxn,i))break;	
				if(cnt[i]==1){
					if(k-cur==1)continue;
					if(k-cur==2){
						int m=mx(m1,i);if(m==0)continue;
						debug(i),debug(m);
						take(1,m);
						if(take(1,i))break;
					}else if(k-cur>=3){
					
						int mx1=mx(m2,i),mx2=mx(m1,i);
							if(mx1>mx2){
								take(1,mx1);
								mx1=mx(m2,i);
								take(1,mx1);
								if(take(1,i))break;
							}else{
								if(mx2==0)continue;
								take(1,mx2);
								if(take(1,i))break;
							}
					}
					
				}else if(cnt[i]==2){
					if(k-cur==3){
						int m=mx(m2,i);
						if(m==0)continue;
						take(2,i);
						if(take(1,m))break;
					}else if(k-cur>3){
							int mx1=mx(m2,i),mx2=mx(m1,i);
							if(mx1>mx2){
								take(1,mx1);
								mx1=mx(m2,i);
								take(1,mx1);
								if(take(2,i))break;
							}else{
								if(mx2==0)continue;
								take(1,mx2);
								if(take(2,i))break;
							}
						}
					}
				}
			}
		
		int flag=0;
		rep(i,1,9)flag+=ans[i];
		if(flag==0)cout<<0<<endl;
		else{
			if(flag+ans[0]!=k)cout<<-1<<endl;
			else for(int i=9;i>=0;i--)rep(j,1,ans[i])cout<<i;cout<<endl;
		}
		
	}
}
/* 
n<1e6, 可以nlogn
选k个和为3的倍数的数，排序输出
O(n)排序，桶排
1
998244353 5
9
998244353 1
998244353 2
998244353 3
998244353 4
998244353 5
998244353 6
998244353 7
998244353 8
998244353 9
wr:算法错 写了1个半小时
 */