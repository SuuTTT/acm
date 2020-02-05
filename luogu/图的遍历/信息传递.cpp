#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
//最小的环长
//有向图，所有点出度为1
/* ana: 由出度为1得出 
1.所以环都是独立的，不会相交。
2.没有单链，只有指向环的链

alg1：wa,第一步错了，样例：1，2点都指向3，先从1出发，然后2出发时就wa了
从所有的无入度点出发，
再从剩下的环中任一点出发
alg1.2：
从所有的无入度点出发，染色，避免上面的情形
再从剩下的环中任一点出发

alg2 dfs搜环，一个意思，只是alg1是递推的。

alg3 并查集 不用路径压缩，cnt传递路径长度。
没压缩不知道为什么和alg1一样块，应该是n^2的呀
int n, fa[N], ans = 0x3f3f3f3f;
int get (int x, int &cnt) { //cnt记录环的长度 
    cnt ++;
    if (fa[x] == x) return x;
    else return get(fa[x], cnt);
}
int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        fa[i] = i;
    for (int i = 1; i <= n; i ++) {
        int cnt = 0, f;
        scanf("%d", &f);
        if (get(f, cnt) == i) {
            ans = min(ans, cnt); //维护最小的环 
        }else
            fa[i] = f;
    }
    printf("%d", ans);
    return 0;
}

alg4 tarjan
 */
int to[maxn];
int in[maxn];
int vis[maxn];
int dfn[maxn];
int ans=0;
void find(int i,int color){
        int cur=i,dep=0;
        dfn[cur]=dep++;
        vis[cur]=color;
        while(dfn[to[cur]]==-1){
            cur=to[cur];
            dfn[cur]=dep++;
            vis[cur]=color;
        }
       
         if(vis[to[cur]]==color)ans=min(ans,dep-dfn[to[cur]]);
}
int main(){
    ans=(int)1e6;
    int n;
    cin>>n;
    fill(dfn,dfn+n+1,-1);
    rep(i,1,n)cin>>to[i],in[to[i]]++;
    rep(i,1,n){
        if(in[i]==0){
            find(i,i);
        }
    }
    rep(i,1,n){
            if(dfn[i]!=-1)continue;
            find(i,i);
    } 
        
    cout<<ans<<endl;
}
/* 
2
2 1
 */