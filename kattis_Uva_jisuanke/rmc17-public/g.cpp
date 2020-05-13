#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}
/* 
G 给出在0~2^n-1对应的二进制串（从右往左）在01trie树上走到的叶子节点的值（走到叶子就不走了），问构造这个树最少几个节点。
 */