#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}
/* 
贪心，找最小值，后面的买完。repeat。
细节：买多了一次80单位的糖

2 
3 3 2 
200 10 399 
300 8 499 
400 12 499 
2 5 10 
9 10 199 
8 20 99 
 */