#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}
/* 
E  两个人轮流切网格， 每次选一片切一下。不能切的输。
Harry只能横着切 Vicky只能竖着切。
给出网格大小，问H/V先手的是否能赢
 */