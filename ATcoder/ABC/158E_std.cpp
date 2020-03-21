#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=1e4+10;
char s[N];int n,p,f[M];
ll ans,sum=0,x=1;
 
int main() {
	scanf("%d %d",&n,&p);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) s[i]-='0';
	if(p==2||p==5) {
		for(int i=1;i<=n;i++)
			if(s[i]%p==0)
				ans+=i;
	}
	else {
		for(int i=n; i;i--) {
			sum=(sum+x*s[i])%p;
			x=x*10%p;
			f[sum]++;
		}
		ans=f[0]+(1LL*f[0]*(f[0]-1)>>1);
		for(int i=1;i<p;i++)
			ans+=1LL*f[i]*(f[i]-1)>>1;
	}
	printf("%lld\n",ans);return 0;
}