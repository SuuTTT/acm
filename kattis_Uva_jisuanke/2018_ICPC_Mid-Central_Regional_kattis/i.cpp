#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

typedef double db;
const db eps=1e-7;
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
    bool operator < (const Point &b)const{return x<b.x;}
};
Point GetNode(Point a,Point u,Point b,Point v){return a+u*((v/(a-b))/(u/v));}
db PolyArea(const vector<Point> &P){int n=(int)P.size();db a=0;rep(i,0,n-1)a+=P[i]/P[(i+1)%n];return fabs(a)/2.0;}
vector<double> shift(const vector<double> &p,int x){
    vector<double> q(p.size()+x,0);
    rep(i,0,(ll)p.size()-1)q[i+x]=p[i];
    return q;
}
vector<double> integral(const vector<double> &p){
    vector<double> q(p.size()+1,0);
    rep(i,0,(ll)p.size()-1)q[i+1]=p[i]/(i+1);
    return q;
}
double cal(const vector<double> &p,double x){
    double ans=0;
    for(ll i=(ll)p.size()-1;i>=0;i--)ans=ans*x+p[i];
    return ans;
}
class block{
public:
    Point a,b,c,d;
    vector<double> w;
    void show(){
        cout<<"  "<<a.x<<","<<a.y<<"  "<<b.x<<","<<b.y<<"  "<<c.x<<","<<c.y<<"  "<<d.x<<","<<d.y<<endl;
    }
    void solve(){
        w.clear();
        if(fabs(a.x-b.x)>eps){
            double k1=(b.y-a.y)/(b.x-a.x),b1=k1*(-a.x)+a.y;
            double k2=(d.y-c.y)/(d.x-c.x),b2=k2*(-c.x)+c.y;
            w=(vector<double>){b1-b2,k1-k2};
        }
    }
    double get_integral(int t){
        vector<double> p=integral(shift(w,t));
        return cal(p,b.x)-cal(p,a.x);
    }
    double self_integral(){
        if(w.size()==0)return 0;
        double u=a.x,v=b.x,k=w[1],b=w[0];
        return -(1.0/6)*(((1.0/5)*u*u+(3.0/5)*u*v+(1.0/5)*v*v)*k*k+b*(u+v)*k+b*b)*(u-v)*(u-v)*(u-v);
    }
};

ll n;
vector<Point> P,U,V;
vector<block> B;
vector<double> val[2],sum[2];

void split(){
    int l=0,r=0;
    rep(i,0,n-1){
        if(P[i]<P[l])l=i;
        if(P[r]<P[i])r=i;
    }
    U.clear();V.clear();
    if(fabs(P[  (l+1)%n].x-P[l].x)<eps)l=  (l+1)%n;
    if(fabs(P[(r+n-1)%n].x-P[r].x)<eps)r=(r+n-1)%n;
    for(ll i=l;;i=(i+1)%n){
        U.emplace_back(P[i]);
        if(i==r)break;
    }
    if(fabs(P[(l+n-1)%n].x-P[l].x)<eps)l=(l+n-1)%n;
    if(fabs(P[  (r+1)%n].x-P[r].x)<eps)r=  (r+1)%n;
    for(ll i=l;;i=(i+n-1)%n){
        V.emplace_back(P[i]);
        if(i==r)break;
    }
    //for(auto i:U)cout<<" "<<i.x<<","<<i.y;
    //cout<<endl;
    //for(auto i:V)cout<<" "<<i.x<<","<<i.y;
    //cout<<endl;
}
void make_block(){
    B.clear();
    ll u=0,v=0;
    Point pu=U[0],pv=V[0];
    block b;
    while(u+1<U.size() && v+1<V.size()){
        if(U[u+1]<V[v+1]){
            b.a=pu;
            b.b=U[u+1];
            b.c=pv;
            b.d=GetNode(V[v],V[v+1]-V[v],U[u+1],Point(0,1));
            B.emplace_back(b);
            u++;
            pu=b.b;pv=b.d;
        }else{
            b.a=pu;
            b.b=GetNode(U[u],U[u+1]-U[u],V[v+1],Point(0,1));
            b.c=pv;
            b.d=V[v+1];
            B.emplace_back(b);
            v++;
            pu=b.b;pv=b.d;
        }
    }
    //for(auto b:B)b.show();
}
double solve(){
    split();
    make_block();
    for(auto &b:B)b.solve();
    val[0].resize(B.size());
    val[1].resize(B.size());
    rep(i,0,(ll)B.size()-1)val[0][i]=B[i].get_integral(0),val[1][i]=B[i].get_integral(1);
    //rep(i,0,(ll)B.size()-1)cout<<" "<<val[0][i]<<endl;
    sum[0]=val[0];sum[1]=val[1];
    rep(i,1,(ll)B.size()-1)sum[0][i]+=sum[0][i-1],sum[1][i]+=sum[1][i-1];
    double ans=0;
    rep(i,0,(ll)B.size()-1)ans+=B[i].self_integral();
    //cout<<" ans="<<ans<<endl;
    rep(i,1,(ll)B.size()-1){
        ans+=val[1][i]*sum[0][i-1]-val[0][i]*sum[1][i-1];
    }
    ans/=PolyArea(P)*PolyArea(P);
    ans*=2;
    return ans;
}

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n){
        P.resize(n);
        rep(i,0,n-1)cin>>P[i].x>>P[i].y;
        double ans=solve();
        rep(i,0,n-1)swap(P[i].x,P[i].y);
        reverse(P.begin(),P.end());
        ans+=solve();
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}
/*

*///