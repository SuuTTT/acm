#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int next1[maxn];
void getnext(string t)
{
    int i = 0, j = -1;
    next1[0] = -1;
    while(i < t.size())
    {
        if(j == -1 || t[i] == t[j])
        {
            i++;
            j++;
            next1[i] = j;
        }
        else j = next1[j];
    }
    return ;
}
   
int kmp(string s, string t)
{
    getnext(t);
    int i = 0, j = 0;
    while(i <= s.size())
    {
        if(j == -1 || s[i] == t[j])
        {
            i++;
            j++;
            if(j == 0)
                return 0;
        }
        else j = next1[j];
    }
    return 1;
}
int main()
{
    string s, t;  
    cin >> s >> t;
    if(kmp(s, t)) cout << "Yes";
    else cout <<"No";
    return 0;
}