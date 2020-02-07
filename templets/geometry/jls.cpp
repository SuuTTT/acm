#define Decimal fixed<<setprecision(20)

//typedef long long ll;
const int maxn = 105;
typedef double db;
typedef double ld;
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