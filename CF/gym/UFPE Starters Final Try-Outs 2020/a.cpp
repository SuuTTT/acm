#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define pb push_back
const int maxn=1000005;
char str[maxn],s[maxn];
int p[maxn];
void manacher(char s[],int l)
{
   int i,j,k,ans=0;
   for(i=1;i<=l;++i)str[i<<1]=s[i],str[(i<<1)+1]='#';
   str[1]='#';str[l*2+1]='#';str[0]='&';str[l*2+2]='$';
   debug(str);
   l=l*2+1;j=0;
   for(i=1;i<=l;)
   {
       while(str[i-j-1]==str[i+j+1])++j;
       p[i]=j;if(j>ans)ans=j;
       for(k=1;k<=j&&p[i]-k!=p[i-k];++k)p[i+k]=min(p[i-k],p[i]-k);
       i+=k;j=max(j-k,0);
   }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    int len=strlen(s+1);
    manacher(s,len);
    int flag=0;
    rep(i,0,len*2+1)cout<<p[i];//if(m<=p[i]&&(m%2==p[i]%2))flag=1;
    puts(flag?"Accept":"Reject");
}
/*
10 3
ajabbaaksj
*/