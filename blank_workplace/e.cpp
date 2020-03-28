#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
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
   // point(double x,double y) 
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

int intersect(db l1,db r1,db l2,db r2){
    if (l1>r1) swap(l1,r1); if (l2>r2) swap(l2,r2); return cmp(r1,l2)!=-1&&cmp(r2,l1)!=-1;
}
int checkSS(point k1,point k2,point k3,point k4){
    return intersect(k1.x,k2.x,k3.x,k4.x)&&intersect(k1.y,k2.y,k3.y,k4.y)&&
    sign(cross(k3-k1,k4-k1))*sign(cross(k3-k2,k4-k2))<=0&&
    sign(cross(k1-k3,k2-k3))*sign(cross(k1-k4,k2-k4))<=0;
}
/* ------------------------------- */


int sx,sy,ex,ey;
int w,h,n;
int vis[65][65][70][70];
int dir[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
point P[7][2];
struct node{
    int x,y,vx,vy,t;
    node(int x,int y,int vx,int vy,int t):x(x),y(y),vx(vx),vy(vy),t(t){};
};
void V(node i){vis[i.x][i.y][i.vx+33][i.vy+33]=1;}
bool border(node v){
    if(v.x<0||v.x>=w||v.y<0||v.y>=h)return 1;
    if(abs(v.vx)>32||abs(v.vy)>32)return 1;
    return 0;
}
bool inter(node p1,node p2){
    rep(i,1,n){
        if(checkSS(P[i][0],P[i][1],{(db)p1.x,(db)p1.y},{(db)p2.x,(db)p2.y}))return 1;
    }
    return 0;
}
int bfs(){
    memset(vis,0,sizeof(vis));
    queue<node> Q;
    Q.push(node(sx,sy,0,0,0));
    while(!Q.empty()){
        node now=Q.front();
        //debug(1),debug(now.x),debug(now.y),debug(now.vx),debug(now.vy),debug(now.t);
        if(now.x==ex&&now.y==ey&&now.vx==0&&now.vy==0){
            //debug(ex),debug(ey);
            return now.t;}
        V(now);
        Q.pop();
        
        rep(i,0,4){
            int dvx=now.vx+dir[i][0];
            int dvy=now.vy+dir[i][1];
            int dx=now.x+dvx;
            int dy=now.y+dvy;
            node tmp(dx,dy,dvx,dvy,now.t+1);
            if(border(tmp))continue;
            if(inter(now,tmp))continue;
            if(vis[tmp.x][tmp.y][tmp.vx+33][tmp.vy+33])continue;
            V(tmp);
            Q.push(tmp);
        }
    }
   return 0;
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>w>>h){
        cin>>sx>>sy>>ex>>ey;
        cin>>n;
        rep(i,1,n){   
            P[i][0].scan();
            P[i][1].scan();
        }
        cout<<bfs()<<endl;
    }
}
/* 
2 1 0 0 1 0 0
2 2 0 0 1 1 0
4 2 1 0 2 1 2 0 1 1 1 2 0 3 0
9 9 8 3 8 5 4 8 4 5 1 5 1 2 4 2 4 5 7 5 7 8 4
9 9 2 2 7 8 6 0 6 4 3 6 8 3 7 1 7 4 1 3 6 7 0 4 1 1 2 5 7 6 3

 */