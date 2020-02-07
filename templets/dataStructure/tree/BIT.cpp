#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
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
//poj2352 Stars
int level[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    bit.init(maxn-1);
    rep(i,1,n){
        int x,y;
        cin>>x>>y;
        x++;y++;
        level[bit.query(x)]++;
        // debug(x),debug(bit.query(x));
        bit.update(x,1);
        
       
    }
    rep(i,0,n-1){cout<<level[i]<<endl;}
}
/*
5
1 1
5 1
7 1
3 3
5 5
*/