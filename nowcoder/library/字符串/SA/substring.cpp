
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
const int MAXN=50000*6+5;
 
int len;
int S[MAXN];
int wa[MAXN],wb[MAXN],wsf[MAXN],wv[MAXN],sa[MAXN];
int ranks[MAXN],height[MAXN],s[MAXN];
char str[MAXN];
 
bool cmp(int *r,int a,int b,int k){
    return r[a]==r[b]&&r[a+k]==r[b+k];
}
 
void get_sa(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++)
        wsf[i]=0;
    for(i=0; i<n; i++)
        wsf[x[i]=r[i]]++;
    for(i=1; i<m; i++)
        wsf[i]+=wsf[i-1];
    for(i=n-1; i>=0; i--)
        sa[--wsf[x[i]]]=i;
 
    for(p=1,j=1; p<n; j*=2,m=p){
        for(p=0,i=n-j; i<n; i++)
            y[p++]=i;
        for(i=0; i<n; i++)
            if(sa[i]>=j)
                y[p++]=sa[i]-j;
        for(i=0; i<n; i++)
            wv[i]=x[y[i]];
        for(i=0; i<m; i++)
            wsf[i]=0;
        for(i=0; i<n; i++)
            wsf[wv[i]]++;
        for(i=1; i<m; i++)
            wsf[i]+=wsf[i-1];
        for(i=n-1; i>=0; i--)
            sa[--wsf[wv[i]]]=y[i];
        t=x;
        x=y;
        y=t;
        x[sa[0]]=0;
        for(p=1,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)? p-1:p++;
    }
}
 
 
void get_height(int *r,int n)
{
    int i,j,k=0;
    for(i=0; i<n; i++)
        ranks[sa[i]]=i;
    for(i=0; i<n; i++){
        if(k)
            k--;
        j=sa[ranks[i]-1];
        while(r[i+k]==r[j+k])
            k++;
        height[ranks[i]]=k;
    }
}
 
int f[8][4];
int temp[4]={1,2,3};
int main(){
 //   freopen("in.txt","r",stdin);
    int ind=0;
    do{//枚举所有的映射方案
        for(int i=0;i<3;i++)
            f[ind][i]=temp[i];
        ind++;
    }while(next_permutation(temp,temp+3));
 
    int n;
    while(~scanf("%d",&n)){
        LL ans=0;
        scanf("%s",str);
 
        int longest=0,temp=1;
        for(int i=1;i<n;i++){
            if(str[i]==str[i-1])    temp++;
            else{
                longest=max(longest,temp);
                temp=1;
            }
        }
        longest=max(longest,temp);
        ans=longest*3;//单一字符的本质不同的总子串数等于最长单一字符子串的长度乘 3
 
        len=0;
        for(int i=0;i<6;i++){
            for(int j=0;j<n;j++)
                S[len++]=f[i][str[j]-'a'];
            S[len++]=i+4;//在末尾加上“独特”的字符
        }
        S[len-1]=0;
        get_sa(S,sa,len,10);
        get_height(S,len);//后缀数组模板
 
        for(int i=0;i<len;i++)
            ans+=len-sa[i]-height[i];//计算不同子串个数，详见罗穗骞论文《后缀数组——处理字符串的有力工具》
        ans-=1ll*(n+1)*(6*(len+1)-21*(n+1));//减去独特子串对答案的影响
        printf("%lld\n",ans/6);
    }
 
    return 0;
}
/* 
首先 所谓映射：使得 A 中的每一个字符 c 对应的 f(c) 等于 B 中相应位置的字符。而且映射函数要满足对于 a ≠ b，f(a) ≠ f(b).
abc 
acb
bac
bca
cab
cba

每一个子串 可以映射成6个不同的串。
special case:字符都一样的 只对应3个不同的串. 计算答案时要补3倍的本质不同串
把原串映射成为6个串，对于任意一个串，6个形态都出现了。求之中本质不同的串，所有映射相同的串都被去重，最后/6即为答案
SA https://ac.nowcoder.com/discuss/102005?type=101&order=0&pos=1&page=1&channel=-1
SAM https://ac.nowcoder.com/discuss/87367?type=101&order=0&pos=2&page=1&channel=-1
 */