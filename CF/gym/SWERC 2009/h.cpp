#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
typedef double db;
typedef long long ll;
const int maxn=(int)1e6+5;
const double eps = 1e-7;
const double pi = acos(-1.);
inline int sign(double d) { return d<-eps ? -1 : d>eps; }
inline int cmp(db a, db b) { return sign(a - b); }
struct P {
	db x, y;
	P() {};
	P(db x, db y) :x(x), y(y) {}
	void read() { cin >> x >> y; }
	void write() { cout << '(' << x << ',' << y << ')'; }
	P operator + (P o) { return P(x + o.x, y + o.y); }
	P operator - (P o) { return P(x - o.x, y - o.y); }
	P operator *(db d) { return P(x * d, y * d); }
	P operator /(db d) { return P(x / d, y / d); }
	db operator *(P o) { return (x*o.x + y * o.y); }
	db operator |(const P &o) const{ return x * o.y - y * o.x; }
	bool operator==(P p)const {
		return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
	}
    bool operator < (const P k1) const{
        int a=cmp(x,k1.x);
        if (a==-1) return 1; else if (a==1) return 0; else return cmp(y,k1.y)==-1;
    }
	db abs() { return (x*x + y * y); }
	db abs2() { return (x*x + y * y); }
	db distTo(P p) { return (*this - p).abs(); }
	db alpha() { return atan2(y, x); }
	P rot90() { return P(-y, x); }
	P rot(db a) { return P(x*cos(a) - y * sin(a), x*sin(a) + y * cos(a)); }
	P unit() { return *this / abs(); }
	int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
}p[maxn], q[maxn];

vector<P> ConvexHull(vector<P>A, int flag = 1) { // flag=0 不严格 flag=1 严格 ，不用极角排序
	int n = A.size(); vector<P>ans(n * 2);
	sort(A.begin(), A.end()); int now = -1;
	for (int i = 0; i<A.size(); i++) {
		while (now>0 && sign((ans[now] - ans[now - 1])| (A[i] - ans[now - 1]))<flag) now--;
		ans[++now] = A[i];
	} int pre = now;
	for (int i = n - 2; i >= 0; i--) {
		while (now>pre&&sign((ans[now] - ans[now - 1])|( A[i] - ans[now - 1]))<flag) now--;
		ans[++now] = A[i];
	} ans.resize(now); return ans;
}

/*
	输入的是某点到ch[0]的向量。
	凸包是顺时针存的。
	要求凸包点不共线
*/
struct pt {
	long long x, y;
	pt(long long _x = 0, long long _y = 0) :x(_x), y(_y) {}
	pt operator+(const pt & p) const { return pt(x + p.x, y + p.y); }
	pt operator-(const pt & p) const { return pt(x - p.x, y - p.y); }
	bool operator<(const pt & p) const { return x < p.x || (x == p.x && y < p.y); }
	long long operator*(pt o) { return x * o.x + y * o.y; }
	long long operator|(pt o) { return x * o.y - o.x * y; }
	long long cross(const pt & p) const { return x * p.y - y * p.x; }
	long long dot(const pt & p) const { return x * p.x + y * p.y; }
	long long cross(const pt & a, const pt & b) const { return (a - *this).cross(b - *this); }
	long long dot(const pt & a, const pt & b) const { return (a - *this).dot(b - *this); }
	long long sqrLen() const { return this->dot(*this); }

};

pt L[maxn], S[maxn];
vector<pt> seq;
int n;
bool pointInTriangle(pt a, pt b, pt c, pt point) {
	long long s1 = abs(a.cross(b, c));
	long long s2 = abs(point.cross(a, b)) + abs(point.cross(b, c)) + abs(point.cross(c, a));
	return s1 == s2;
}
int sgn(long long val) {
	return val > 0 ? 1 : (val == 0 ? 0 : -1);
}
bool lexComp(const pt & l, const pt & r) {
	return l.x < r.x || (l.x == r.x && l.y < r.y);
}
void prepare(vector<pt> & points) {
	n = points.size();
	n--;
    seq.clear();
	seq.resize(n);
	for (int i = 0; i < n; i++)
		seq[i] = points[i + 1] - points[0];
	seq.push_back(seq.front());
}
bool pointInConvexPolygon(pt point) {
	if (seq[0].cross(point) != 0 && sgn(seq[0].cross(point)) != sgn(seq[0].cross(seq[n - 1])))
		return false;
	if (seq[n - 1].cross(point) != 0 && sgn(seq[n - 1].cross(point)) != sgn(seq[n - 1].cross(seq[0])))
		return false;

	if (seq[0].cross(point) == 0)
		return seq[0].sqrLen() >= point.sqrLen();

	int l = 0, r = n ;
	while (l <= r) {
		int mid = (l + r) / 2;
		int pos = mid;
		if (seq[pos].cross(point) >= 0)r = mid - 1;
		else l = mid + 1;
	}
   //debug(r),debug(seq[r].x),debug(seq[r].y),debug(seq[r+1].x),debug(seq[r+1].y);
	int pos = r;
	return pointInTriangle(pt(0,0),seq[pos], seq[pos + 1],  point);
}
vector<pt>  ch2;
int inmid(db k1,db k2,db k3){return sign(k1-k3)*sign(k2-k3)<=0;}// k3 在 [k1,k2] 内 
int inmid(P k1,P k2,P k3){return inmid(k1.x,k2.x,k3.x)&&inmid(k1.y,k2.y,k3.y);}

int onS(P k1,P k2,P q){return inmid(k1,k2,q)&&sign((k1-q)|(k2-k1))==0;}
int contain(vector<P>A,P q){ // 2 内部 1 边界 0 外部
    int pd=0; A.push_back(A[0]);
    for (int i=1;i<A.size();i++){
        P u=A[i-1],v=A[i];
        if (onS(u,v,q)) return 1; if (cmp(u.y,v.y)>0) swap(u,v);
        if (cmp(u.y,q.y)>=0||cmp(v.y,q.y)<0) continue;
        if (sign((u-v)|(q-v))<0) pd^=1;
    }
    return pd<<1;
}

vector<P> inn,inm,ch;
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    rep(T,1,t){
        cout<<"Case "<<T<<endl;
        int nn,mm;
        cin>>nn>>mm;
        inn.clear(),inm.clear();
        rep(i,1,nn){
            P p;p.read();
            inn.push_back(p);
        }
        rep(i,1,mm){
            P p;p.read();
            inm.push_back(p);
        }
        ch.clear();
        ch=ConvexHull(inn,1);
        for(auto t:ch){cout<<t.x<<' '<<t.y<<endl;}
        cout<<ch[0].x<<' '<<ch[0].y<<endl;
        ch2.clear();
       // for(auto t:ch)ch2.push_back({(ll)t.x,(ll)t.y});
        //prepare(ch2);
        rep(i,0,mm-1){
            pt now={(ll)inm[i].x-ch2[0].x,(ll)inm[i].y-ch2[0].y};
            cout<<inm[i].x<<' '<<inm[i].y<<' ';
           // if(pointInConvexPolygon(now))
           int f=contain(ch,inm[i]);
           if(f==2) {cout<<"is unsafe!"<<endl;}
            else cout<<"is safe!"<<endl;
        }
        cout<<endl;

        
    }
}
/* 
2
5 2
-52 -325
104 420
315 356
-192 8
493 146
404 228
-239 484
6 5
-477 -180
31 -266
-474 28
147 49
323 -53
277 -79
346 488
-139 -183
-427 129
386 -222
-408 -315



 */