# 知识点 - trie 与AC自动机



## 解决问题类型：

在文本串中查找所有模式串

求和给定字符串集合不匹配的字典序最小的长度为L的c串

求包含给定字符串集合的最短串

求字典序最小的长度为L的包含k个串的串

论文：

2009  浅析字母树在信息学竞赛中的应用   **字母树**

[blog](https://www.cnblogs.com/SuuT/p/11385373.html)

## 定义与代码：

### trie

trie树是每条边都代表某个字母的有根树，结点的出边权值都不同。叶子结点会有一个标记，代表这个结点对应了一个给定的字符。

```cpp
const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}
```

 $O(m k)$ 的空间复杂度可以通过map降到 $O(m)$

### AC自动机

将trie树看成一种自动机，建立后缀链接（suffix link）

```cpp
const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 
```



## 例题



- [UVA #11590 - Prefix Lookup](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2637)
- [UVA #11171 - SMS](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2112)
- [UVA #10679 - I Love Strings!!](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1620)
- [Codeforces - Frequency of String](http://codeforces.com/problemset/problem/963/D)

