# 2019_ICPC_Mid-Central_Regional

## 3 签到题 想法题 

AIL

FJC

## 0 银牌



## 2 金牌

H 数据结构
D 计算几何
K DP
B 图论



### B

一个边权为1的DAG，求删掉一边后X选的最长路的最小值。

这里的删边X是不知道的，即X选了一条最长路开始走，一直走到被删的那条边的端点时才会知道边不见了，然后在那个点开始找当前最长路。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int vis[N], d[N], d2[N],//当前点为起点的最长路
int cnt[N],
int ans[N];
vector<int> G[N];
int dfs(int x) {
	if (vis[x] == 1) return d[x];
	vis[x] = 1;
	for (int u : G[x]) {
		int tmp = dfs(u) + 1;
		if (tmp > d[x]) {//松弛最长路
			d2[x] = d[x];
			d[x] = tmp;
		}
		else if (tmp > d2[x]) {//松弛次长路
			d2[x] = tmp;
		}
	}
	return d[x];
}
void dfs2(int x, int d_up = 0) {
	if (vis[x] == 2) return;
	vis[x] = 2;
	for (int u : G[x]) {
		if (d[x] == d[u] + 1) {//如果是最长路上的点
			dfs2(u, d_up + 1);
			cnt[d_up] ++;
			ans[d_up] = d_up + d2[x];
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) G[0].push_back(i);//*超级源点
	for (int i = 0; i < m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	dfs(0);
	dfs2(0);
	int res = d[0];
	for (int i = 1; i <= n; ++ i) if (cnt[i] == 1) res = min(res, ans[i]);
	printf("%d\n", res - 1);
}


```





## 捧杯

E 
G