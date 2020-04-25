#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn],p[maxn];
bool cmp(int aa,int b){
    return a[aa]>a[b];
}
pair<int,int> a[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n){
        int x;cin>>x;
    }
    sort(p+1,p+1+n,cmp);
    rep(i,1,n)debug(p[i]);
    int l=1,r=n;
    rep(i,1,n){
        int pt=l;
        if(abs(l-p[i])<abs(r-p[i]))pt=r;
        swap(a[i],a[pt]);

    }
}
/* 
ana:
贪心：从大到小移到两边 没有正确性，因为考虑两边的那个数换到中间后，轮到它时选较大的一边不是最优的（要选和初始移动方向相同的那一边）
注意到方向，|i-p[i]|=max(i-p[i],p[i]-i)
 */