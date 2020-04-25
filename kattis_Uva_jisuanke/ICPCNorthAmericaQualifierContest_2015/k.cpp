#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

const double eps=1e-7;
struct Point{
    ll x,y;
    Point(){}
    Point(ll x,ll y):x(x),y(y){}
    Point operator + (const Point &b)const{return Point(x+b.x,y+b.y);}
    Point operator - (const Point &b)const{return Point(x-b.x,y-b.y);}
    Point operator * (ll b)const{return Point(x*b,y*b);}
    Point operator / (ll b)const{return Point(x/b,y/b);}
    ll operator * (const Point &b)const{return x*b.x+y*b.y;}
    ll operator / (const Point &b)const{return x*b.y-y*b.x;}
    double length()const{return sqrt(x*x+y*y);}
};

template<ll n> class uset{
public:
    ll Set[n+1];
    ll find(ll x){
        if(Set[x]!=x)Set[x]=find(Set[x]);
        return Set[x];
    }
    void init(int n_){
        rep(i,1,n_)Set[i]=i;
    }
    void unionset(ll x,ll y){
        Set[y]=x;
    }
    void connect(ll x,ll y){
        ll r1=find(x),r2=find(y);
        if(r1!=r2)unionset(r1,r2);
    }
};

Point P[205];
ll n,r[205];
uset<205> use;

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n){
        rep(i,1,n)cin>>P[i].x>>P[i].y>>r[i];
        use.init(n+2);
        rep(i,1,n){
            if(abs(P[i].x-0)<=r[i])use.connect(i,n+1);
            if(abs(P[i].x-200)<=r[i])use.connect(i,n+2);
            rep(j,1,i-1)if((P[i]-P[j]).length()<r[i]+r[j]+eps)use.connect(i,j);
            if(use.find(n+1)==use.find(n+2)){
                cout<<i-1<<endl;
                break;
            }
        }
    }
    return 0;
}
/* 
圆圈隔断巨型走廊，加二分

check O(n) 暴力也是o(n)不用二分，直接枚举过去
 */