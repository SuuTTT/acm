#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef double db;
const db eps=1e-6;
const db pi=acos(-1);
int sign(db k){
    if (k>eps) return 1; else if (k<-eps) return -1; return 0;
}
int cmp(db k1,db k2){return sign(k1-k2);}
int inmid(db k1,db k2,db k3){return sign(k1-k3)*sign(k2-k3)<=0;}// k3 在 [k1,k2] 内 
struct point{
    db x,y;
    point operator + (const point &k1) const{return (point){k1.x+x,k1.y+y};}
    point operator - (const point &k1) const{return (point){x-k1.x,y-k1.y};}
    point operator * (db k1) const{return (point){x*k1,y*k1};}
    point operator / (db k1) const{return (point){x/k1,y/k1};}
    int operator == (const point &k1) const{return cmp(x,k1.x)==0&&cmp(y,k1.y)==0;}
    // 逆时针旋转 
    point turn(db k1){return (point){x*cos(k1)-y*sin(k1),x*sin(k1)+y*cos(k1)};}
    point turn90(){return (point){-y,x};}
    bool operator < (const point k1) const{
        int a=cmp(x,k1.x);
        if (a==-1) return 1; else if (a==1) return 0; else return cmp(y,k1.y)==-1;
    }
    db abs(){return sqrt(x*x+y*y);}
    db abs2(){return x*x+y*y;}
    db dis(point k1){return ((*this)-k1).abs();}
    point unit(){db w=abs(); return (point){x/w,y/w};}
    void scan(){double k1,k2; scanf("%lf%lf",&k1,&k2); x=k1; y=k2;}
    void print(){printf("%.11lf %.11lf\n",x,y);}
    db getw(){return atan2(y,x);} 
    point getdel(){if (sign(x)==-1||(sign(x)==0&&sign(y)==-1)) return (*this)*(-1); else return (*this);}
	int getP() const{return sign(y)==1||(sign(y)==0&&sign(x)==-1);}
};
int n;
db w,b,d,s;
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>w>>b>>d>>s;
        int q;cin>>q;
        int ans=0;
        while(q--){
            point p;
            p.scan();
            //debug(p.getw());
            if(cmp(p.abs2(),b*b)==-1){ans+=50;continue;}
            if(cmp(p.abs2(),s*s)==1){continue;}
            double factor=1;
            if(inmid(b,d,p.abs()))factor=2;
            double a=p.getw();
            if(cmp(a,0)==-1)a+=2*pi;
            double score=a/2/pi*w;
            ans+=(int)ceil(score)*(int)factor;
            //debug(ans);
        }
        cout<<ans<<endl;
    }
}
/* 
3
4 7 13 10
4
1 1
-1 1
-1 -1
1 -1

3
4 7 13 10
2
4.000 4.000
6.000 -4.000
10 1 6 10
1
20.000 -0.500
8 3 7 50
5
-0.750 1.207
1.180 3.132
27.111 -44.630
-43.912 -22.104
2.000 -6.000
 */