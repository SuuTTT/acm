#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;

/* 
整数二分
0.如果二分下标，注意越界丧失单调性or搜出去
1.单调性
x越大越成立，换言之：x轴自变量，应变量是check函数，值域为0、1且关于x单调，


 */
bool check(int x){
    return x>=0;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int l=-5,r=5;
    //x>=0的最小值
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))r=mid-1;//x越大越满足
        else l=mid+1;
    }
    debug(l);
    //x>=0的最小值
    l=-5,r=5;
    while(l+1 < r) {//差1格   index0?
        long long m = (l+r) / 2;
        if (m>=0) r = m;
        else l = m;
    }
    debug(r);
    //x<0的最大值
    l=-5,r=5;
    while(l+1 < r) {//差1格   index0?
        long long m = (l+r) / 2;
        if (m<0) l = m;
        else r = m;
    }
    debug(l);
    
    //x<0的最大值
    l=-5,r=5;
    while(l<=r){
        int mid=(l+r)/2;
        if(mid<0)l=mid+1;//x越大越满足
        else r=mid-1;
    }
    debug(r);
}

/* 
 while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))l=mid+1;//x越小越满足
        else r=mid-1;
}
cout<<r;
 */
/* 
  while(l+1 < r) {//差1格   index0?
        long long m = (l+r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
cout << l << endl;
 */