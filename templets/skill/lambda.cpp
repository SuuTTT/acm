#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;

struct node{
    int x,val;

}a[3];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    a[0]={1,3};a[1]={2,2};a[2]={3,1};
    sort(a,a+3,[&](node a,node b){
        return a.val<b.val;
    });
    rep(i,0,2)debug(a[i].val);
}