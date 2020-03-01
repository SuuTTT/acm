#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
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
    Point flip()const{return Point(y,-x);}
    bool operator == (const Point &b)const{return x==b.x && y==b.y;}
    ll operator * (const Point &b)const{return x*b.x+y*b.y;}
    ll operator / (const Point &b)const{return x*b.y-y*b.x;}
    bool operator < (const Point &b)const{
        if(x!=b.x)return x<b.x;
        return y<b.y;
    }
};
class PointSet{
public:
    bool a[2005][2005];
    vector<Point> v;
    ll count(const Point &p)const{
        if(p.x<0 || p.x>2000 || p.y<0 || p.y>2000)return 0;
        return a[p.x][p.y];
    }
    void insert(const Point &p){
        if(p.x<0 || p.x>2000 || p.y<0 || p.y>2000)return;
        v.push_back(p);
        a[p.x][p.y]=1;
    }
    void clear(){
        for(auto p:v)a[p.x][p.y]=0;
        v.clear();
    }
};

ll n;
Point P[1005];
PointSet all;
set<Point> ans;

void init(){
    all.clear();
    rep(i,1,n)all.insert(P[i]);
}
bool check(Point u){
    rep(i,1,n)if(all.count(P[i]-u)==0 && all.count(P[i]+u)==0)return false;
    return true;
}
ll solve(){
    ans.clear();
    rep(i,1,n)rep(j,1,n)if(i!=j && check(P[j]-P[i]))ans.insert(P[j]-P[i]);
    return ans.size();
}

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n){
        rep(i,1,n)cin>>P[i].x>>P[i].y;
        rep(i,1,n)P[i]=P[i]+Point(1000,1000);
        init();
        cout<<solve()<<endl;
    }
    return 0;
}
/*

*///