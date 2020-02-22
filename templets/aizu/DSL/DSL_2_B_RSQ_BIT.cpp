#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
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
BIT<int, maxn>bit;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    bit.init(n);
    rep(i,1,q){
        int op,x,y;
        cin>>op>>x>>y;
        if(op)cout<<bit.query(y)-bit.query(x-1)<<endl;
        else bit.update(x,y);
    }

}
/* 

3 5
0 1 1
0 2 2
0 3 3
1 1 2
1 2 2
 */