#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int lc,pc,lm,pm,t,d;
int a[MAXN];
ll smotor[MAXN],scar[MAXN],needmotor[MAXN];
int canmotor[MAXN],cancar[MAXN];//需要的age
ll motordrain[MAXN],cardrain[MAXN],sdrain[MAXN];//可贡献的age
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%d%d%d%d",&lc,&pc,&lm,&pm);
    scanf("%d%d",&t,&d);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++)
    {
        if(a[i]+d<lc) cancar[i]=0; else
        {
            cancar[i]=1;//可以加age当驾驶员
            scar[i]=max(0,lc-a[i]);//要当驾驶员需要的age
        }
        if(a[i]+d<lm) canmotor[i]=0; else
        {
            canmotor[i]=1;
            smotor[i]=max(0,lm-a[i]);
        }
        sdrain[i]=min(a[i]-1,d);//可贡献的age
        if(a[i]>=lc) cardrain[i]=min(d,a[i]-lc);//当驾驶员可贡献的age
        if(a[i]>=lm) motordrain[i]=min(d,a[i]-lm);
        //全部求前缀和
        sdrain[i]+=sdrain[i-1];
        cardrain[i]+=cardrain[i-1];
        motordrain[i]+=motordrain[i-1];
        cancar[i]+=cancar[i-1];
        canmotor[i]+=canmotor[i-1];
        scar[i]+=scar[i-1];
        smotor[i]+=smotor[i-1];
    }
    ll ans=INF;
    for(int i=0;;i++)
    {
        if(cancar[i]<i) break;//枚举需要的car驾驶员
        int l=i+1,r=max(i,n-i*(k-1));//r是去掉乘车人员后的人数
        if(l<=r&&canmotor[r]-canmotor[l-1]!=r-l+1) continue;
        ll candrain=cardrain[i]+sdrain[n]-sdrain[r]+motordrain[r]-motordrain[l-1];
        if(candrain<(scar[i]+smotor[r]-smotor[l-1])) continue;
        int len=(l>r?0:r-l+1);
        ans=min(ans,1LL*i*pc+1LL*len*pm+1LL*t*scar[i]+(l>r?0:1LL*t*(smotor[r]-smotor[l-1])));
        if(k*i>=n) break;
    }
    if(ans==INF) puts("-1"); else printf("%lld\n",ans);
    return 0;
}
/* 
题意看错，摩托车不能载人!
多数组记录多属性

 */