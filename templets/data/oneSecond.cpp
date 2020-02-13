#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;

/* 
整数二分
 */
bool check(int x){
    return x>=0;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int l=L,r=R;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
}