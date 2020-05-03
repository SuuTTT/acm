#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
//输入的串是s，生成长为2l+3的str串，p数组对应str串的回文半径。
/*


10 
ajabbaaksj
str:&#a#j#a#b#b#a#a#k#s#j#$
p:  0010301014101210101010
i->i*2+2
i->(i-2)/2
*/

string s;
char str[maxn];
int p[maxn];
int manacher(string s)
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
   return max_element(p,p+l*2+3);
}
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    //for(auto t:pi)debug(t);
    return pi;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1,s2;
    int ans=0;
    ans=max(ans,manacher(s1));
    ans=max(ans,manacher(s1));
    string tmp=s1+'#'+s2;
}
/* 
两个串，分别取子串拼接，两个串首尾下标相同,求最长的回文串
case 1.串内：manacher
case 2.串外：枚举中点，hash O(1)比较，二分查找,
 */