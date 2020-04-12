#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
typedef long long ll;
const int maxn=(int)1e6+5;
/* 
下标从1开始的
a[i]=sum(lowit_i..i)
 */
template<typename T, size_t size>
struct BIT {
	T a[size]; int n;
	void init(int _n) { n = _n; memset(a, 0, sizeof(T)*(_n + 1)); }//输入下标范围。
	void erase(int x) { for (int i = x; i <= n; i += i & -i)a[i] = 0; }
	void update(int x, T y) {
		for (int i = x; i <= n; i += i & -i)a[i] += y;
	}
	T query(int x) { T re = 0;  for (int i = x; i; i -= i & -i)re += a[i]; return re; }
};
BIT<ll, maxn>bit;

int a[maxn],pos[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        bit.init(n);
        rep(i,1,n){
            cin>>a[i];pos[a[i]]=i;
            bit.update(i,a[i]);
        }
        
        
        int last=1;
        ll sum=n*(n+1)/2;
        ll ans=0;
        rep(i,1,n){
            int now=pos[i];
            int l=min(now,last);
            int r=max(now,last);
            ll tmp=bit.query(r-1)-bit.query(l-1);
            ans+=min(tmp,sum-tmp);
            sum-=a[now];
            bit.update(now,-i);
            last=now;
        }
        cout<<ans<<endl;
    }
}

/* 
I: 一个1~n排列的栈，只能从头部取数字。可以花费数字的值将头部的数字放到尾部或尾部的数字放到头部。
求按照1~n的顺序取出所有数字的最小花费

2
5 3 5 1 4 2
3 1 2 3
 */