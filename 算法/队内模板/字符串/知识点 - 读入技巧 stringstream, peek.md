# 知识点 - 读入技巧 stringstream, peek



## 解决问题类型：

cin.peek():观察

cin.get():获取：

```cpp
    while (cin.peek() != '\n')
        {
            n = 0;
            a = 0;
            op = 1;
            if ('-' == cin.peek())
            {
                cin.get();
                op = -1;
            }
         } 

```

stringstream: 可以当作输入输出流的string。自带string->int 转换。



## 例题与代码:

[A+B problem](https://ac.nowcoder.com/acm/contest/887/J)

将AB反过来，加，再反回去。

```cpp
#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include <sstream>
using namespace std;
const int N = 15, K = 60;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        stringstream ss;
        ss << s1;
        long long  x1,x2;
        ss >> x1;
        ss.clear();
        ss << s2;
        ss >> x2;
        //cout << x1 << ' ' << x2;
        x1 += x2;
        ss.clear();
        ss << x1;
        ss >> s1;
        reverse(s1.begin(), s1.end());
        ss.clear();
        ss << s1;
        ss >> x1;
        cout << x1 << endl;
    }
     
}
```

