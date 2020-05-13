#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;
typedef long double db;

const db eps=1e-6;
const db pi=acos(-1.0);
struct Point{
    db x,y;
    Point(){}
    Point(db x,db y):x(x),y(y){}
    Point operator + (const Point &b)const{return Point(x+b.x,y+b.y);}
    Point operator - (const Point &b)const{return Point(x-b.x,y-b.y);}
    Point operator * (db b)const{return Point(x*b,y*b);}
    Point operator / (db b)const{return Point(x/b,y/b);}
    bool operator == (const Point &b)const{return fabs(x-b.x)<eps && fabs(y-b.y)<eps;}
    db operator * (const Point &b)const{return x*b.x+y*b.y;}
    db operator / (const Point &b)const{return x*b.y-y*b.x;}
    db length()const{return sqrt(x*x+y*y);}
};
ll dcmp(db x){return fabs(x)<eps?0:x>0?1:-1;}
ll dcmp(db x,db y){return dcmp(x-y);}
db Dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
db Cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
Point Rotate(Point p,db t){return Point(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));}
Point Rotate(Point p,db cost,db sint){return Point(p.x*cost-p.y*sint,p.x*sint+p.y*cost);}
db Dis(Point a,Point b){return (a-b).length();}
Point GetNode(Point a,Point u,Point b,Point v){return a+u*((v/(a-b))/(u/v));}
db PolyArea(Point *P,int n){db a=0;rep(i,0,n-1)a+=P[i]/P[(i+1)%n];return fabs(a)/2.0;}
db DisToLine(Point a,Point m,Point n){return fabs((a-m)/(a-n)/Dis(m,n));}
db Angle(Point u,Point v){return acos(u*v/u.length()/v.length());}

db r;
Point dir;
bool check(Point S,Point T,Point V){
    db d=DisToLine(T,S,S+V);
    if(dcmp(d,2*r)>0)return false;
    if(dcmp(V*(T-S))<0)return false;
    db sint=d/(2*r),cost=sqrt(4*r*r-d*d)/(2*r);
    if(dcmp(V/(T-S))>0){
        dir=Rotate(V,cost,sint);
    }else{
        dir=Rotate(V,cost,-sint);
    }
    return true;
}
Point P[5],V;
ll solve(){
    if(check(P[1],P[2],V)){
        if(check(P[2],P[3],dir))return 1;
        else return 3;
    }else if(check(P[1],P[3],V)){
        if(check(P[3],P[2],dir))return 2;
        else return 4;
    }else{
        return 5;
    }
}

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>P[1].x>>P[1].y){
        cin>>P[2].x>>P[2].y>>P[3].x>>P[3].y;
        cin>>V.x>>V.y>>r;
        cout<<solve()<<endl;
    }
    return 0;
}
/*

*///