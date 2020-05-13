#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int a[maxn],tot=0;
int dp[maxn],head[maxn];
int ans[maxn];
struct node{
	int next,to;
}edge[maxn*2];
void add_edge(int u,int v){
	tot++;
	edge[tot].next=head[u];
	edge[tot].to=v;
	head[u]=tot;
}
//lower bound
int binary_search(int low,int high,int key){
	int mid,ans=1;
	while(low<=high){
		mid=(high+low)>>1;
		if(dp[mid]>=key) ans=mid,high=mid-1;
		else low=mid+1;
	}
	return ans;
}
void dfs(int u,int fa,int pos){
	int pre,tmp;
	if(dp[pos]<a[u]) pos++,tmp=pos;
	else tmp=binary_search(1,pos,a[u]);
	pre=dp[tmp];
	dp[tmp]=a[u];
	ans[u]=pos;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa) continue;
		dfs(v,u,pos);
	}
	dp[tmp]=pre;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++){
		int tmp,tmp2;
		scanf("%d%d",&tmp,&tmp2);
		add_edge(tmp,tmp2);
		add_edge(tmp2,tmp);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1]=a[1];
	dfs(1,0,1);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}
