#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

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
};
ll PolyArea(Point *P,int n){ll a=0;rep(i,0,n-1)a+=P[i]/P[(i+1)%n];return abs(a);}

ll n;
Point P[1005];

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll ans=0,t;
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,0,n-1)cin>>P[i].x>>P[i].y;
        ans+=PolyArea(P,n);
    }
    cout<<ans/2<<endl;
    return 0;
}
/*

*///