# LIS+字典序

## 题意

给定1e5的数组，1e4个询问：L。

求长度为L的严格上升序列。如果有多个满足条件，那么我们想求字典序最小的那个。

[HAOI2007上升序列](https://www.luogu.org/problem/P2215)

## 题解

从后往前求一遍最长下降子序列（这题建议打二分的，因为a数组没有给定范围，所以树状数组离散化太麻烦）。然后从前往后扫一遍判断当前是否合法（以当前为结尾的lis长度是否超过还需要的长度）就行了。

## 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],f[100001],b[100001],tot;
int query(int x){
    int l=1,r=tot,ans=0,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(b[mid]>x){
            ans=max(ans,mid);
            l=mid+1;
        }
         else r=mid-1;
    }
    return ans;
}
int main(){
    int i,j,t,la,now;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=n;i;i--){
        now=query(a[i]);
        f[i]=now+1;
        tot=max(tot,now+1);
        if(b[now+1]<a[i])b[now+1]=a[i];
    }
    //printf("%d\n",tot);
    scanf("%d",&m);
    while(m--){
        scanf("%d",&t);
        if(t>tot)puts("Impossible");
         else{
            la=0;
            for(j=1;j<=n;j++)
             if(f[j]>=t&&a[j]>la){
                printf("%d ",a[j]);
                t--;la=a[j];
                if(!t)break;
             }
             puts("");
         }
    }
}
```

