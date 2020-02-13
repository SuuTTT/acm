#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}
/* 
 a[i] \in 0,1,2

a_i-1/a_i<a_i/a_i+1
 a[i - 1] * a[i + 1] ≤ a[i]^2.

0 0 0
0 1 0
0 2 0

0 _ _

_ _ 0 


1 2 1

 */