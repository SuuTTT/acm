#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}
/* 
维护差分数组
A(i)-A(i-1) 的区间最大值和最小值，1操作就是判断区间最大最小值是否都为0，2操作就是区间加值以及端点处单点加值
 */