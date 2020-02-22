#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e5+5;
typedef long long ll;
template<typename T, size_t size>
struct BIT {
	T a[size]; int n;
	void init(int _n) { n = _n; memset(a, 0, sizeof(T)*(_n + 1)); }
	void erase(int x) { for (int i = x; i <= n; i += i & -i)a[i] = 0; }
	void update(int x, T y) {
		//debug(x);
		for (int i = x; i <= n; i += i & -i)a[i] += y;
	}
	T query(int x) { T re = 0;  for (int i = x; i; i -= i & -i)re += a[i]; return re; }
};
BIT<ll, maxn>bit;
int flag[maxn];
int cnt[26][maxn];
int cur[256];
int lastpos[maxn];
map<char,int> memo;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    s=' '+s;
    int len=s.size();
    len--;
    rep(i,1,len){
        cnt[s[i]-'a'][i]++;
        lastpos[i]=memo[s[i]];
        memo[s[i]]=i;
    }
    rep(i,1,len)rep(j,0,25){
        cnt[j][i]+=cnt[j][i-1];
    }
    //rep(i,1,len)cout<<lastpos[i];
    /* rep(i,1,len)rep(j,0,1){
        debug(i),debug(j),debug(cnt[j][i]);
    } */
    int ans=0;
    rep(i,1,len){
        int tot=0;
        rep(j,0,25)if(j!=s[i]-'a'){
            if(cnt[j][i]-cnt[j][lastpos[i]])tot++;
            //debug(j),debug(i),debug(cnt[s[i]-'a'][i]),debug(cnt[s[i]-'a'][lastpos[i]]);
        }
        //debug(i),debug(tot);
        ans+=tot;
    }
    cout<<ans<<endl;
}
/* abab */
//abbcccddddeeeee