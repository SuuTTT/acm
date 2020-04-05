#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e5+5;


#define mp make_pair
#define fi first
#define se second
#define pb push_back
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
int inmid(point k1,point k2,point k3){return inmid(k1.x,k2.x,k3.x)&&inmid(k1.y,k2.y,k3.y);}
db cross(point k1,point k2){return k1.x*k2.y-k1.y*k2.x;}
db dot(point k1,point k2){return k1.x*k2.x+k1.y*k2.y;}
db rad(point k1,point k2){return atan2(cross(k1,k2),dot(k1,k2));}
// -pi -> pi, 向外
int compareangle (point k1,point k2){
    return k1.getP()<k2.getP()||(k1.getP()==k2.getP()&&sign(cross(k1,k2))>0);
}

/* ---相交，距离--- */
int clockwise(point k1,point k2,point k3){// k1 k2 k3 逆时针 1 顺时针 -1 否则 0  
    return sign(cross(k2-k1,k3-k1));
}
int checkLL(point k1,point k2,point k3,point k4){ // 直线 (L) 线段 (S)k1,k2 和 k3,k4 的交点
    return cmp(cross(k3-k1,k4-k1),cross(k3-k2,k4-k2))!=0;
}
point getLL(point k1,point k2,point k3,point k4){
    db w1=cross(k1-k3,k4-k3),w2=cross(k4-k3,k2-k3); return (k1*w2+k2*w1)/(w1+w2);
}
int intersect(db l1,db r1,db l2,db r2){
    if (l1>r1) swap(l1,r1); if (l2>r2) swap(l2,r2); return cmp(r1,l2)!=-1&&cmp(r2,l1)!=-1;
}
int checkSS(point k1,point k2,point k3,point k4){
    return intersect(k1.x,k2.x,k3.x,k4.x)&&intersect(k1.y,k2.y,k3.y,k4.y)&&
    sign(cross(k3-k1,k4-k1))*sign(cross(k3-k2,k4-k2))<=0&&
    sign(cross(k1-k3,k2-k3))*sign(cross(k1-k4,k2-k4))<=0;
}

int onS(point k1,point k2,point q){return inmid(k1,k2,q)&&sign(cross(k1-q,k2-k1))==0;}

point l[maxn],r[maxn];
int idx[maxn];
int n;
bool cmp1(int a,int b){
    point k1=r[a]-l[a],k2=r[b]-l[b];
    if((k1.getP()==k2.getP()&&sign(cross(k1,k2))==0)){
        //截距排序
        db x1=k1.x,x2=k2.y,y1=0,y2=0;
        if(x1==0)y1=y2=(db)1e18;
        else{
            y1=l[a].y-k1.y/k1.x*l[a].x;
            y2=l[b].y-k2.y/k2.x*l[b].x;
        }
        if(cmp(y1,y2)==0)
        return cmp(l[a].x,l[b].x)==0?cmp(l[a].y,l[b].y)==-1:cmp(l[a].x,l[b].x)==-1;
        else return cmp(y1,y2)==-1;
    }
    return k1.getP()<k2.getP()||(k1.getP()==k2.getP()&&sign(cross(k1,k2))>0);
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(~scanf("%d,",&n)){
        if(n==0)break;
        rep(i,1,n){
            l[i].scan(),r[i].scan();
            if(!(l[i]<r[i]))swap(l[i],r[i]);
            //l[i].print(),r[i].print();
        }
        rep(i,1,n)idx[i]=i;
        
        sort(idx+1,idx+1+n,cmp1);
        //rep(i,1,n)debug(idx[i]);
       
        int last=idx[1];
        int ans=1;
        rep(j,2,n){
            int i=idx[j];
            point k1=r[last]-l[last],k2=r[i]-l[i];
            //debug(last),debug(i);
            /* if(onS(l[last],r[last],l[i])&&onS(l[last],r[last],r[i])){}
            else{
                if(onS(l[last],r[last],l[i])||onS(l[last],r[last],r[i]))last=i;
                else last=i,ans++;
            } */
            if(!(k1.getP()==k2.getP()&&sign(cross(k1,k2))==0)){
                last=i;ans++;
                //debug(1);
            }else{
                if(onS(l[last],r[last],l[i])&&onS(l[last],r[last],r[i])){}
                else{
                    if(onS(l[last],r[last],l[i])||onS(l[last],r[last],r[i]))last=i;
                    else last=i,ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
/* 
4
0 0 2 2
0 0 -2 -2
0 0 -2 2
0 0 2 -2
8
0 0 2 2
0 0 -2 -2
0 0 -2 2
0 0 2 -2
1 1 3 3
-1 -1 -3 -3
-1 1 -3 3
1 -1 3 -3
2
0 0 0 1
0 1 0 2
2
0 0 0 1
0 1.5 0 2

3
0 0 2 0
1.5 1 3 1
1 0 3 0




3
1.0 10.0 3.0 14.0
0.0 0.0 20.0 20.0
10.0 28.0 2.0 12.0
2
0.0 0.0 1.0 1.0
1.0 1.0 2.15 2.15
2
0.0 0.0 1.0 1.0
1.0 1.0 2.15 2.16
2
1.0 1.0 0.0 0.0 
1.0 1.0 1.0 0.0
0
 */