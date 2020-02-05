# 知识点 - 高斯消元 线性方程组 SLAE

$$a_{11} x_1 + a_{12} x_2 + \dots + a_{1m} x_m = b_1$$
$$a_{21} x_1 + a_{22} x_2 + \dots + a_{2m} x_m = b_2$$
$$\dots$$
$$a_{n1} x_1 + a_{n2} x_2 + \dots + a_{nm} x_m = b_n$$

矩阵形式即

$$Ax = b$$,

模质数下的，求逆元即可。

$$a_{11} x_1 + a_{12} x_2 + \dots + a_{1m} x_m \equiv b_1 \pmod p$$
$$a_{21} x_1 + a_{22} x_2 + \dots + a_{2m} x_m \equiv b_2 \pmod p$$
$$\dots$$
$$a_{n1} x_1 + a_{n2} x_2 + \dots + a_{nm} x_m \equiv b_n \pmod p$$

## 解决问题类型：

## 模板及复杂度



```cpp
/*高斯消元，系数矩阵为a[i][j],i=1…n,j=1…n,常数为a[i][n+1],i=1…n，返回值为是否有唯一解，答案存在a[i][n+1]*/
bool gauss(int n) {
    for (int i = 1; i <= n; i++) {
        int k = i;
        for (int j  = i + 1; j <= n; j++)if (fabs(a[j][i]) > fabs(a[k][i]))k = j;
        if (fabs(del = a[k][i]) < eps)return 0;
        for (int j = i; j <= n + 1; j++)swap(a[i][j], a[k][j]);
        for (int j = i; j <= n + 1; j++)a[i][j] /= del;
        for (k = 1; k <= n; k++)if (k != i) {
            del = a[k][i];
            for (int j = i; j <= n + 1; j++)a[k][j] -= a[i][j] * del;
        }
    }
    return 1;
}
```

下面这个模板未知数和方程数可以不同。读入$A,b$ 矩阵，返回解的个数$(0, 1,\textrm{or } \infty)$. $O(n^3)$.

```cpp
/*
col row 为当前的行，列
where[i]存x_i的第几行不是0，如果为-1则说明这个变量是独立的(可以任意取)
最后把独立变量赋为0，看方程有没有解
*/
int gauss (vector < vector<double> > a, vector<double> & ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;

	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		if (abs (a[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;

		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}

	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
		double sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (abs (sum - a[i][m]) > EPS)
			return 0;
	}

	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return INF;
	return 1;
}
```

模2下的模板，先削成上三角，然后回带$O(nm)$

```cpp
int gauss (vector < bitset<N> > a, int n, int m, bitset<N> & ans) {
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		for (int i=row; i<n; ++i)
			if (a[i][col]) {
				swap (a[i], a[row]);
				break;
			}
		if (! a[row][col])
			continue;
		where[col] = row;

		for (int i=0; i<n; ++i)
			if (i != row && a[i][col])
				a[i] ^= a[row];
		++row;
	}
        // The rest of implementation is the same as above
}
```





## 例题

[Gambler Bo](http://acm.hdu.edu.cn/showproblem.php?pid=5755)

## 代码

```cpp
//https://www.cnblogs.com/forever97/p/hdu5755.html
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
const int N=35;
int ans,n,m,T,a[N][N],p[N][N],f[N][N][N];
int DP(int i,int j,int k){
    int t=(f[i][j-1][k]+2*f[i][j][k]+f[i][j+1][k]+f[i-1][j][k])%3;
    return ((3-t)%3+3)%3;
}
int GetAns(int i,int j){
    int t=(p[i][j-1]+2*p[i][j]+p[i][j+1]+p[i-1][j]+a[i][j])%3;
    return ((3-t)%3+3)%3;
}
void Gauss(int n,int m) { 
    int d,i,j,k,h,w=0; 
    for(i=1,j=1;j<m;j++,w=0){ 
        for(k=i;k<=n;k++)if(p[k][j])w=k; 
        if(w){ 
            for(k=j;k<=m;k++)swap(p[i][k],p[w][k]); 
            for(k=i+1;k<=n;k++) 
            if(p[k][j]){ 
                d=p[k][j]*p[i][j]%3;
                for(h=j;h<=m;h++)p[k][h]=(p[k][h]-d*p[i][h]+6)%3; 
            }i++; 
        }if(i>n)break; 
    }for(j=1;j<=m;j++)f[1][j][j]=0; 
    for(j=i-1;j;j--){ 
        for(k=1;k<m;k++)if(p[j][k])break; 
        for (d=0,h=k+1;h<m;h++)if(f[1][h][h]&&p[j][h])d=(d+f[1][h][h]*p[j][h])%3; 
        f[1][k][k]=p[j][k]*(3-d+p[j][m])%3; 
    }memset(p,0,sizeof(p)); 
    for(j=1;j<=m;j++)p[1][j]=(f[1][j][j]+3)%3; 
} 
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        rep(i,n)rep(j,m)scanf("%d",&a[i][j]);
        memset(f,0,sizeof(f));
        rep(i,m)f[1][i][i]=1;
        rep(i,n)rep(j,m){
            f[i+1][j][m+1]=(3-a[i][j]+DP(i,j,m+1))%3;
            rep(k,m)f[i+1][j][k]=DP(i,j,k);
        }memset(p,0,sizeof(p));
        rep(i,m){
            p[i][m+1]=((3-f[n+1][i][m+1])%3+3)%3;
            rep(j,m)p[i][j]=f[n+1][i][j];
        }Gauss(m,m+1);ans=0;
        rep(i,m)ans+=p[1][i];
        for(int i=2;i<=n;i++)rep(j,m)p[i][j]=GetAns(i-1,j),ans+=p[i][j];
        printf("%d\n",ans);
        rep(i,n)rep(j,m)rep(k,p[i][j])printf("%d %d\n",i,j);
    }return 0;
}
```

