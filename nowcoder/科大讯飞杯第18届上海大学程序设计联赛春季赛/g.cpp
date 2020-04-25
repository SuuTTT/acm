#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}
/* 
链接：https://ac.nowcoder.com/acm/contest/5278/G
来源：牛客网

如果一个节点上有 2 只或 2 只以上的松鼠，他们会打架，然后这个节点上松鼠的数量会减少 1；
根节点的所有松鼠移动到地面，位于地面上的松鼠不会再打架；
所有松鼠同时朝它们的父节点移动。
 */