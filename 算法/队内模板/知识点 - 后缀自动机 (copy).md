# 知识点 - 后缀自动机



## 解决问题类型：

1. 询问一些模式串P是否出现在文本串T中
2. 询问一些模式串P文本串T中出现了几次
3. 询问一些模式串P文本串T中第一次出现的位置
4. 询问一些模式串P文本串T中所有出现的位置
5. S串中有几个不同的子串
6. S串中不同子串的总长度
7. 求S字典序第K大的子串
8. 求S字典序最小的循环位移（cyclic shift）
9. 求S最短的没有出现的子串
10. 求S1，S2的最长公共子串
11. 求 $k$个串 $S_i$的公共子串

论文：

王鉴浩，《浅谈字符串匹配的几种方法》，2015年国家集训队论文。

张天扬，《后缀自动机及其应用》，2015年国家集训队论文。

## 复杂度：

$O(n)$ 时间$O(n k)$空间

或$O(n \log k)$时间$O(n)$空间

k是字母表，用map存的话会多一个log

## 例题

[求本质不同排名第k小的子串](https://www.luogu.org/problem/SP7258)

exe:

[串里长为n的字典序最小的子串](https://www.luogu.org/problem/P1368)



## 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
int n;
char s[1000001];
struct Suffixautomaton{
    struct edge{
        int to,next;
    }e[3000001];
    int cnt=1,last=1,g[2000001][27],pa[2000001],len[2000001],head[2000001],indo[2000001],sz[2000001],tot,id[2000001];
    inline void insert(int ch){
        int pos=last,newp=++cnt;
        last=newp;len[newp]=len[pos]+1;
        for (;pos&&!g[pos][ch];pos=pa[pos]) g[pos][ch]=newp;
        if (!pos) pa[newp]=1;
        else{
            int posx=g[pos][ch];
            if (len[pos]+1==len[posx]) pa[newp]=posx;
            else{
                int vs=++cnt;
                len[vs]=len[pos]+1;
                for (int i=0;i<26;i++) g[vs][i]=g[posx][i];
                pa[vs]=pa[posx];pa[posx]=pa[newp]=vs;
                for (;g[pos][ch]==posx;pos=pa[pos]) g[pos][ch]=vs;
            }
        } 
    }
    inline void bfs(){
        for (int i=1;i<=cnt;i++){indo[len[i]]++;}
        for (int i=1;i<=cnt;i++){indo[i]+=indo[i-1];}
        for (int i=1;i<=cnt;i++){id[indo[len[i]]--]=i;}
        for (int i=cnt;i>=1;i--){
            sz[id[i]]=1;
            for (int j=0;j<26;j++){
                int v=g[id[i]][j];
                if (!v) continue;
                sz[id[i]]+=sz[v];
            }
        }
    }
    inline void query(int k){
        int os=1;
        while (k){
            for (int i=0;i<26;i++){
                if (g[os][i]){
                    if (sz[g[os][i]]>=k){
                        putchar('a'+i);
                        os=g[os][i];
                        k--;break;
                    }else k-=sz[g[os][i]];
                }
            }
        }
        puts("");
    }
}sam;
int main(){
    scanf("%s",s);
    int L=strlen(s);
    for (int i=0;i<L;i++) sam.insert(s[i]-'a');
    sam.bfs();
    int Q;
    cin>>Q;
    while (Q--){
        int W;scanf("%d",&W);
        sam.query(W);
    }
}
```

```
//模板
struct state {
    int len, link;
    map<char, int> next;
};
```

