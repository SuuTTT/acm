#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
tuple<int,int,string,long long ,string> a[maxn];
struct data{//equivalent
    int v, w;
    ll d;
    string t, n;
    data(int _v, int _w, string _t, ll _d, string _n) 
    : v(_v), w(_w), t(_t), d(_d), n(_n) {}

    bool operator < (const data other) const{
        if(v != other.v)    return v < other.v;
        if(w != other.w)    return w < other.w;
        if(t != other.t)    return t < other.t;
        if(d != other.d)    return d < other.d;
        return n < other.n;
    }
};
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n){
        int v,w;
        string c;
        long long d;
        string s;
        cin>>v>>w>>c>>d>>s;
        a[i]=make_tuple(v,w,c,d,s);
    }
    sort(a+1,a+1+n);
    rep(i,1,n){
        cout<<get<0>(a[i])<<' '<<get<1>(a[i])<<' '<<get<2>(a[i])<<' '<<get<3>(a[i])<<' '<<get<4>(a[i])<<endl;
    }

}
/* 
5
105 24 C 1500000000000 white
100 23 C 1500000000000 blue
105 23 A 1480000000000 pink
110 25 B 1500000000000 black
110 20 A 1300000000000 gree
 */