#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

inline int next(void) {
	register int ret = 0;
	register int neg = false;
	register int bit = getchar();
	for (; bit < '0'; bit = getchar())
		if (bit == '-')neg ^= true;
	for (; bit >= '0'; bit = getchar())
		ret = ret * 10 + bit - '0';
	return neg ? -ret : ret;
}

int n, m;

int root;
int cmpk;

struct node {
	int id;
	int pos[2];
	int son[2];
	int min[2];
	int max[2];
	inline friend bool operator < 
		(const node &a, const node &b) {
			return a.pos[cmpk] < b.pos[cmpk];
	}
}tree[500005];

inline void update(int t) {
	for (int k = 0; k < 2; ++k) {
		tree[t].min[k] = tree[t].max[k] = tree[t].pos[k];
		for (int i = 0, s; i < 2; ++i)if (s = tree[t].son[i]) {
			if (tree[t].min[k] > tree[s].min[k])
				tree[t].min[k] = tree[s].min[k];
			if (tree[t].max[k] < tree[s].max[k])
				tree[t].max[k] = tree[s].max[k];
		}
	}
}

int build(int l, int r, int k) {
	int d = (l + r) / 2; cmpk = k;
	nth_element(tree + l, tree + d, tree + r + 1);
	tree[d].son[0] = l == d ? 0 : build(l, d - 1, k ^ 1);
	tree[d].son[1] = r == d ? 0 : build(d + 1, r, k ^ 1);
	return update(d), d;
}

inline void build(void) {
	for (int i = 1; i <= n; ++i) {
		tree[i].id = i - 1;
		tree[i].pos[0] = next();
		tree[i].pos[1] = next();
	}
	root = build(1, n, 0);
}

int st[2], ed[2], ans[500005], tot = 0;

inline bool judge(const node &t) {
	return t.pos[0] >= st[0]
		&& t.pos[0] <= ed[0]
		&& t.pos[1] >= st[1]
		&& t.pos[1] <= ed[1];
}

inline bool check(const node &t) {
	return t.min[0] <= ed[0]
		&& t.max[0] >= st[0]
		&& t.min[1] <= ed[1]
		&& t.max[1] >= st[1];
}

void query(int t) {
	if (judge(tree[t]))ans[tot++] = tree[t].id;
	if (tree[t].son[0] && check(tree[tree[t].son[0]]))query(tree[t].son[0]);
	if (tree[t].son[1] && check(tree[tree[t].son[1]]))query(tree[t].son[1]);
}

inline void query(void) {
	for (int i = 0; i < m; ++i, tot = 0) {
		st[0] = next();
		ed[0] = next();
		st[1] = next();
		ed[1] = next();
		tot = 0;
		query(root);
		sort(ans, ans + tot);
		for (int j = 0; j < tot; ++j)
			printf("%d\n", ans[j]);
		puts("");
	}
}

signed main(void) {
	n = next(); build();
	m = next(); query();
	//system("pause");
}
