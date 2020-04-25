#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+10;
char s[maxn];
int leaf[maxn],q[maxn],fail[maxn],tot;
int son[maxn][26];
int id,pos[maxn];
/* 给定n个模式串和1个文本串，求有多少个模式串在文本串里出现过。 */
void insert(){
  scanf("%s",s);
  for(int l=strlen(s),x=0,i=0,w;i<l;i++){
    if(!son[x][w=s[i]-'a'])son[x][w]=++tot;x=son[x][w];
    if(i==l-1)leaf[x]++,pos[++id]=x;//统计数量
    else leaf[x]++;
  }
}
int make(){
  int h=1,t=0,i,j,x;fail[0]=-1;
  for(i=0;i<26;i++)if(son[0][i])q[++t]=son[0][i];
  while(h<=t)for(x=q[h++],i=0;i<26;i++)
    if(son[x][i]){
     // leaf[son[x][i]]+=leaf[ fail[son[x][i]]=son[fail[x]][i] ];

      fail[son[x][i]]=son[fail[x]][i];
      q[++t]=son[x][i];
    }else son[x][i]=son[fail[x]][i];
    return t;
}
int main(){
    int n;cin>>n;
    rep(i,1,n)insert();
    int t=make();
    for(int i=t;i>=0;i--)leaf[fail[q[i]]]+=leaf[q[i]];//串s出现一次，串s的后缀也出现一次
    rep(i,1,n)cout<<leaf[pos[i]]<<endl;
}
/* 
字典里每个单词出现的次数
3
a
aa
aaa
 */