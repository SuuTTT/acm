//输入的串是s，生成长为2l+1的str串，p数组对应str串的回文半径。
/*
10 
ajabbaaksj
str:&#a#j#a#b#b#a#a#k#s#j#$
p:  0010301014101210101010
*/
const int maxn=1000005;
char str[maxn],s[maxn];
int p[maxn];
void manacher(char s[],int l)
{
   int i,j,k,ans=0;
   for(i=1;i<=l;++i)str[i<<1]=s[i],str[(i<<1)+1]='#';
   str[1]='#';str[l*2+1]='#';str[0]='&';str[l*2+2]='$';
   l=l*2+1;j=0;
   for(i=1;i<=l;)
   {
       while(str[i-j-1]==str[i+j+1])++j;
       p[i]=j;if(j>ans)ans=j;
       for(k=1;k<=j&&p[i]-k!=p[i-k];++k)p[i+k]=min(p[i-k],p[i]-k);
       i+=k;j=max(j-k,0);
   }
}