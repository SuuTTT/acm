#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}

/* 
1 2 1
1 2 1 3 (2 3)1
1 2 1 3 1 4 (2 3 2 4(3 4))1
(1 2 1 3 1 4 1 5 (2 3 2 4 2 5 (3 4 3 5 (4 5 ()))) 1)
 */