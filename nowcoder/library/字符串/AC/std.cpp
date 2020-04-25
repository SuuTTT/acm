#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e6 + 5;
const int M = 26;
const int C = 'a';
 
struct AC
{
    int tr[maxn][M], cnt[maxn], fail[maxn], endpos[maxn];
    int q[maxn], tot, head, tail;
     
    void insert(char *s, int id)
    {
        int p = 0;
        for (int i = 0; s[i]; ++i)
        {
            int ch = s[i] - C;
            if (tr[p][ch] == 0) tr[p][ch] = ++tot;
            p = tr[p][ch], ++cnt[p];
        }
        endpos[id] = p;
    }
     
    void build()
    {
        head = 0, tail = -1;
        for (int i = 0; i < M; ++i)
            if (tr[0][i]) q[++tail] = tr[0][i];
        while (head <= tail)
        {
            int p = q[head++];
            for (int i = 0; i < M; ++i)
                if (tr[p][i])
                    fail[tr[p][i]] = tr[fail[p]][i], q[++tail] = tr[p][i];
                else tr[p][i] = tr[fail[p]][i]; 
        }
    }
}ac;
 
int n;
char s[maxn];
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s), ac.insert(s, i);
    ac.build();
    //for (int i = ac.tail; i >= 0; --i) ac.cnt[ac.fail[ac.q[i]]] += ac.cnt[ac.q[i]];
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ac.cnt[ac.endpos[i]]);
    return 0;
}