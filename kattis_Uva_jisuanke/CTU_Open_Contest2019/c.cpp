#include<bits/stdc++.h>
#define inf 1000000000000
#define M 100009
#define eps 1e-12
#define PI acos(-1.0)
using namespace std;
struct Point
{
    double x,y;
    Point(){}
    Point(double xx,double yy){x=xx;y=yy;}
    Point operator -(Point s){return Point(x-s.x,y-s.y);}
    Point operator +(Point s){return Point(x+s.x,y+s.y);}
    double operator *(Point s){return x*s.x+y*s.y;}
    double operator ^(Point s){return x*s.y-y*s.x;}
}p[M];
double max(double a,double b){return a>b?a:b;}
double min(double a,double b){return a<b?a:b;}
double len(Point a){return sqrt(a*a);}
double dis(Point a,Point b){return len(b-a);}//两点之间的距离
double cross(Point a,Point b,Point c)//叉乘
{
    return (b-a)^(c-a);
}
double dot(Point a,Point b,Point c)//点乘 
{
    return (b-a)*(c-a);
}
int judge(Point a,Point b,Point c)//判断c是否在ab线段上（前提是c在直线ab上）
{
    if (c.x>=min(a.x,b.x)
       &&c.x<=max(a.x,b.x)
       &&c.y>=min(a.y,b.y)
       &&c.y<=max(a.y,b.y)) return 1;
    return 0;
}
double area(Point b,Point c,double r)
{
    Point a(0.0,0.0);
    if(dis(b,c)<eps) return 0.0;
    double h=fabs(cross(a,b,c))/dis(b,c);
    if(dis(a,b)>r-eps&&dis(a,c)>r-eps)//两个端点都在圆的外面则分为两种情况
    {
        double angle=acos(dot(a,b,c)/dis(a,b)/dis(a,c));
        if(h>r-eps) return 0.5*r*r*angle;else 
        if(dot(b,a,c)>0&&dot(c,a,b)>0)
        {
            double angle1=2*acos(h/r);
            return 0.5*r*r*fabs(angle-angle1)+0.5*r*r*sin(angle1);
        }else return 0.5*r*r*angle;
    }else 
        if(dis(a,b)<r+eps&&dis(a,c)<r+eps) return 0.5*fabs(cross(a,b,c));//两个端点都在圆内的情况
        else//一个端点在圆上一个端点在圆内的情况
        {
            if(dis(a,b)>dis(a,c)) swap(b,c);//默认b在圆内
            if(fabs(dis(a,b))<eps) return 0.0;//ab距离为0直接返回0
            if(dot(b,a,c)<eps)
            {
                double angle1=acos(h/dis(a,b));
                double angle2=acos(h/r)-angle1;
                double angle3=acos(h/dis(a,c))-acos(h/r);
                return 0.5*dis(a,b)*r*sin(angle2)+0.5*r*r*angle3;
            }else
            {
                double angle1=acos(h/dis(a,b));
                double angle2=acos(h/r);
                double angle3=acos(h/dis(a,c))-angle2;
                return 0.5*r*dis(a,b)*sin(angle1+angle2)+0.5*r*r*angle3;
            }
        }
}
int main()
{
    int T,n=4;
    double rx,ry,R;
   
    scanf("%lf%lf%lf",&rx,&ry,&R);
    scanf("%lf%lf%lf%lf",&p[1].x,&p[1].y,&p[3].x,&p[3].y);
    p[2].x=p[1].x;p[2].y=p[3].y;
    p[4].x=p[3].x;p[4].y=p[1].y;
    p[5]=p[1];
    Point O(rx,ry);
    for (int i=1;i<=n+1;i++) p[i]=p[i]-O;
    O=Point(0,0);
    double sum=0;
    for (int i=1;i<=n;i++)
    {
        int j=i+1;
        double s=area(p[i],p[j],R);
        if (cross(O,p[i],p[j])>0) sum+=s;else sum-=s;
    }
    printf("%.4lf\n",fabs(sum));
   
    return 0;
}
/* 
1
0 0 1 -1000 -1000 1000 1000
0 0 1 1 0 3 3
-1 0 2 -1 -2 3 2
 */