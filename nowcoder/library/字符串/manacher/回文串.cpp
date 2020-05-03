#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
//输入的串是s，生成长为2l+3的str串，p数组对应str串的回文半径。
/*


10 
ajabbaaksj
str:&#a#j#a#b#b#a#a#k#s#j#$
p:  0010301014101210101010
i->i*2+2
i->i-2/2
*/
const int maxn=1000005;
string s;
char str[maxn];
int p[maxn];
void manacher(string s)
{
    int l=s.length();
   int i,j,k,ans=0;
   for(i=1;i<=l;++i)str[i<<1]=s[i-1],str[(i<<1)+1]='#';
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
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>s){
        
        
        manacher(s);
        cout<<*max_element(p,p+2*s.length()+3)<<endl;
        
    }
}

/* 
a
aa
aaa
aqppqole
ebcml
 */