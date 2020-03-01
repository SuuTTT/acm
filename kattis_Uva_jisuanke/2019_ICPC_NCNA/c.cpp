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
struct line{
    ll a,b,c;
    void make_line(const Point &A,const Point &B){
        a=A.y-B.y;
        b=B.x-A.x;
        c=-A.x*(A.y-B.y)+A.y*(A.x-B.x);
    }
    int check(const Point &A){
        return a*A.x+b*A.y+c>0?1:0;
    }
};

Point A[10005],B[10005],P,Q;
line L[10005];
ll n,T;

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n){
        rep(i,1,n)cin>>A[i].x>>A[i].y>>B[i].x>>B[i].y;
        rep(i,1,n)L[i].make_line(A[i],B[i]);
        cin>>T;
        while(T--){
            cin>>P.x>>P.y>>Q.x>>Q.y;
            int f=0;
            rep(i,1,n)f+=(L[i].check(P)!=L[i].check(Q));
            cout<<(f%2==0?"same":"different")<<endl;
        }
    }
    return 0;
}
/*

*///