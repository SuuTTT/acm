# 知识点 - manacher



## 解决问题类型：

线性计算回文半径。

注意这个半径是包括添加的字符的：

&#a#b#a#$ ：p=0 0 1 0 3 0 1 0 0





## 例题

### 题意：

[Colorful String](https://nanti.jisuanke.com/t/41389)

定义串s对答案的贡献是其不同字符数。问某个串S的所有回文串的贡献之和。

### 分析：

先跑一边马拉车。

对每个字母计算其贡献。

```cpp
const int maxn = 3e5 + 5;
char s[maxn];
char str[maxn*2];
int p[maxn*2];
int l;
void manacher(char s[], int l)
{
	int i, j, k, ans = 0;
	for (i = 1; i <= l; ++i)str[i << 1] = s[i], str[(i << 1) + 1] = '#';
	str[1] = '#'; str[l * 2 + 1] = '#'; str[0] = '&'; str[l * 2 + 2] = '$';
	l = l * 2 + 1; j = 0;
	for (i = 1; i <= l;)
	{
		while (str[i - j - 1] == str[i + j + 1])++j;
		p[i] = j; if (j>ans)ans = j;
		for (k = 1; k <= j && p[i] - k != p[i - k]; ++k)p[i + k] = min(p[i - k], p[i] - k);
		i += k; j = max(j - k, 0);
	}
}
int nxt[26][maxn];
int main()
{
	FAST_IO;
	scanf("%s", s + 1);
	l = strlen(s + 1);
	manacher(s, l);
	//l = l * 2 + 1;
	rep(c, 0, 25) {
		//int len = strlen(s + 1);
		nxt[c][l+1] = l + 1;
		per(i, l, 1) {
			if (s[i] == c+'a')nxt[c][i] = i;
			else nxt[c][i] = nxt[c][i + 1];
		}
	}
	ll ans = 0;
	rep(i, 1, l) {
		rep(c, 0, 25) {
			ans += max(0, i + (p[i * 2] - 1) / 2 - nxt[c][i] + 1);
			ans+=max(0,i+(p[i*2+1]/2)-nxt[c][i]+1);
		}
	}
	cout << ans-l << endl;
	//cin >> str;
}
/*
abac
cabac
ccacc
cccaaa
abcdefghijklmnopqrstuvwxyz
*/
```

