#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
vector<int> a(5,1);
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    accumulate(a.begin(),a.end(),0);
    for(auto t:a)debug(t);
}
/* 
accumulate
 */