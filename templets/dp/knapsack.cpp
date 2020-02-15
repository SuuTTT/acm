#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//01背包 无优化
    for(int i=1;i<=n;i++)
{
    for(int c=0;c<=m;c++)
    {
        f[i][c]=f[i-1][c];
        if(c>=w[i])
        f[i][c]=max(f[i][c],f[i-1][c-w[i]]+v[i]);
    }
}
//降维优化
for(int i=1;i<=n;i++)
{
    for(int c=m;c>=0;c--)
    {
        if(c>=w[i])
        f[c]=max(f[c],f[c-w[i]]+v[i]);
    }
}
//常数优化
for(int i=1;i<=n;i++)
{
    sumw+=w[i];
    bound=max(m-sumw,w[i]);
    for(int c=m;c>=bound;c--)
    {
        if(c>=w[i])
        f[c]=max(f[c],f[c-w[i]]+v[i]);
    }
}
//完全背包
for(int i=1;i<=n;i++)
{
    for(int c=0;c<=m;c++)
    {
        if(c>=w[i])
        f[c]=max(f[c],f[c-w[i]]+v[i]);
    }
}
//多重背包
for(int i=1;i<=n;i++)
{
    if(w[i]*a[i]>m)//完全背包
    {
        for(int c=0;c<=m;c++)
        {
        if(c>=w[i])
        f[c]=max(f[c],f[c-w[i]]+v[i]);
        }
    }
    else
    {
         k=1;amount=a[i];
         while(k<amount)
         {
             for(int c=k*w[i];c>=0;c--)
             {
                 if(c>=w[i])
                 f[c]=max(f[c],f[c-w[i]]+k*v[i]);
             }
             amount-=k;
             k<<=1;
         }  
         for(int c=amount*w[i];c>=0;c--)
         {
             f[c]=max(f[c],f[c-w[i]]+amount*v[i]);
         }
    } 
}
}
