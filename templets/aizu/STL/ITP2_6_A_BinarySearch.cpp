#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n)cin>>a[i];
    int q;cin>>q;while(q--){
        int k;cin>>k;
        int l=1,r=n;
        while(l<=r){
            int mid=l+r>>1;
            if(a[mid]>=k)r=mid-1;
            else l=mid+1;
        }
        cout<<(a[l]==k)<<endl;
    }
}