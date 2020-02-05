# 知识点 - 后缀数组 (SA)



## 解决问题类型：

最小的循环位移（cyclic shift，即字符环中字典序最小）

查找子串

比较两个子串

两个子串的LCP(不需要额外空间)

本质不同的子串数

论文

2009后缀数组——处理字符串的有力工具 罗穗骞   **后缀数组**

2004 后 缀 数 组 许智磊    **后缀数组**

[blog](https://www.cnblogs.com/SuuT/p/11385353.html)

## 定义与代码：

$sa[i]$表示s串后缀中第 $i$ 小的后缀位置。

$s = abaab$ 的 $sa$ 数组：$(2,~ 3,~ 0,~ 4,~ 1)$.



$rk[i]$代表s串的 $suffix[i]$ 在$sa$ 的位置。

$height[i]$ 为$sa[i-1],sa[i]$的LCP长度。

具体实现有倍增或DC3.

这里先给出一种cyclic shift的$O(nlogn)$求法

```cpp
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
```



## 例题



- [Uva 760 - DNA Sequencing](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=701)
- [Uva 1223 - Editor](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3664)
- [Codechef - Tandem](https://www.codechef.com/problems/TANDEM)
- [Codechef - Substrings and Repetitions](https://www.codechef.com/problems/ANUSAR)
- [Codechef - Entangled Strings](https://www.codechef.com/problems/TANGLED)
- [Codeforces - Martian Strings](http://codeforces.com/problemset/problem/149/E)
- [Codeforces - Little Elephant and Strings](http://codeforces.com/problemset/problem/204/E)
- [SPOJ - Ada and Terramorphing](http://www.spoj.com/problems/ADAPHOTO/)
- [SPOJ - Ada and Substring](http://www.spoj.com/problems/ADASTRNG/)
- [UVA - 1227 - The longest constant gene](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3668)
- [SPOJ - Longest Common Substring](http://www.spoj.com/problems/LCS/en/)
- [UVA 11512 - GATTACA](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2507)
- [LA 7502 - Suffixes and Palindromes](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=720&page=show_problem&problem=5524)
- [GYM - Por Costel and the Censorship Committee](http://codeforces.com/gym/100923/problem/D)
- [UVA 1254 - Top 10](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3695)
- [UVA 12191 - File Recover](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3343)
- [UVA 12206 - Stammering Aliens](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3358)
- [Codechef - Jarvis and LCP](https://www.codechef.com/problems/INSQ16F)
- [LA 3943 - Liking's Letter](https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1944)
- [UVA 11107 - Life Forms](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2048)
- [UVA 12974 - Exquisite Strings](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=862&page=show_problem&problem=4853)
- [UVA 10526 - Intellectual Property](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1467)
- [UVA 12338 - Anti-Rhyme Pairs](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3760)
- [DevSkills Reconstructing Blue Print of Life](https://devskill.com/CodingProblems/ViewProblem/328)
- [UVA 12191 - File Recover](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3343)
- [SPOJ - Suffix Array](http://www.spoj.com/problems/SARRAY/)
- [LA 4513 - Stammering Aliens](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2514)
- [SPOJ - LCS2](http://www.spoj.com/problems/LCS2/)
- [Codeforces - Fake News (hard)](http://codeforces.com/contest/802/problem/I)
- [SPOJ - Longest Commong Substring](http://www.spoj.com/problems/LONGCS/)
- [SPOJ - Lexicographical Substring Search](http://www.spoj.com/problems/SUBLEX/)
- [Codeforces - Forbidden Indices](http://codeforces.com/contest/873/problem/F)
- [Codeforces - Tricky and Clever Password](http://codeforces.com/contest/30/problem/E)
- [LA 6856 - Circle of digits](https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4868)

