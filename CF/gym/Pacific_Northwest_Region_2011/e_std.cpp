#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8; 
const double PI=acos(-1.0); 
const int INF=0x3f3f3f3f;
int sgn(double x) 
{
	if(fabs(x)<eps)return 0;
	if(x<0)return -1;
	else return 1;
}
struct Point
{
	int x,y;
	Point(){}
	Point(int _x,int _y)
	{
		x=_x;y=_y;
	}
	Point operator - (const Point &b)const
	{
		return Point(x-b.x,y-b.y); 
	}
	double operator ^ (const Point &b)const//叉积
	{
		return x*b.y-y*b.x;
	}
	double operator * (const Point &b)const//点积
	{
		return x*b.x+y*b.y;
	}
};
struct Line
{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e)
	{
		s = _s;e = _e;
	}
}L[10];
bool inter(Line l1,Line l2) 
{ 
	return 
    max(l1.s.x,l1.e.x)>=min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x)>=min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y)>=min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y)>=min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 && 
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0; 
}
int w,h,x,y,tx,ty,f;
int book[65][65][70][70];
int dir[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
bool judge(int X,int Y,int tvx,int tvy,int step)
{
	if(X<0||X>=w||Y<0||Y>=h||abs(tvx)>32||abs(tvy)>32)
		return false;
	if(book[X][Y][tvx+33][tvy+33]!=INF)
		return false;
	return true;
}
struct node
{
	int nx,ny,vx,vy,step;
	node(int _nx,int _ny,int _vx,int _vy,int _step):nx(_nx),ny(_ny),vx(_vx),vy(_vy),step(_step){}
};
void bfs(int nx,int ny,int vx,int vy,int step)
{
	queue<node> Q;
	Q.push(node(nx,ny,vx,vy,step));
	book[nx][ny][vx+33][vy+33]=step;
	while(!Q.empty())
	{
		node T=Q.front();
		Q.pop();
		nx=T.nx;ny=T.ny;vx=T.vx;vy=T.vy;step=T.step;
		for(int i=0;i<5;i++)
		{
			Line tL;
			Point s,e;
			int dx=dir[i][0],dy=dir[i][1];
			int tvx=vx+dx,tvy=vy+dy;
			int tnx=nx+tvx,tny=ny+tvy;
			bool flag=false;
			s=Point(nx,ny),e=Point(tnx,tny);
			tL=Line(s,e);
			for(int j=1;j<=f;j++)
			{
				if(inter(tL,L[j]))
				{
					flag=true;
					break;
				}
			}
			if(!flag&&judge(tnx,tny,tvx,tvy,step+1))
			{
				book[tnx][tny][tvx+33][tvy+33]=step+1;
				Q.push(node(tnx,tny,tvx,tvy,step+1));
			}
		}
	}
	
}
void solve()
{
	memset(book,0x3f,sizeof(book));
	scanf("%d%d",&x,&y);
	scanf("%d%d",&tx,&ty);
	scanf("%d",&f);
	for(int i=1;i<=f;i++)
	{
		Point s,e;
		scanf("%d%d",&s.x,&s.y);
		scanf("%d%d",&e.x,&e.y);
		L[i]=Line(s,e);
	}
	bfs(x,y,0,0,0);
	printf("%d\n",book[tx][ty][33][33]);
	int xx,yy,vxx,vyy;
	//while(~scanf("%d%d%d%d",&xx,&yy,&vxx,&vyy))\
	{\
		printf("%d\n",book[xx][yy][vxx+33][vyy+33]);\
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d%d",&w,&h))
	{
		solve();
	}
	return 0;
}