#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[10]; int n;
void print(){
    rep(i,0,n-1)cout<<a[i]<<(i==n-1?'\n':' ');
}
/* 
边间相连。
 */   
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin>>n;
    rep(i,0,n-1){
        cin>>a[i];
    }
    if(prev_permutation(a,a+n))print();
    next_permutation(a,a+n);
    print();
    if(next_permutation(a,a+n))print();
}
/* 
3
1 2 3
3
1 3 2
 */