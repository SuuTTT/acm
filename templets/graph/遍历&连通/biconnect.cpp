#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
//**（点）双连通分量**：没有割点的联通分量
vector<int> edge[maxn];
//各个双连通分量的数组，双连通分量有点的标号的vector表示
vector<vector <int> >connect;
int dfn[maxn], low[maxn], in_seq[maxn];
int stack[man],list[maxn];
int cnt,top,pop,len;
//对每个连通块取一点调用
void biconnect(int v){
    //每次发现一条树边和回边（子节点指向父节点），就将它压入栈中
    stack[++top]=v;
    dfn[v]=low[v]=pop++;
    int i,succ;
    for(i= edge[v].size()-1;i>=0;i--){
        succ=edge[v][i];
        if(dfn[succ]==-1){
            biconnect(succ);
            //当dfs从一个点u返回到点v时，如果low[u]>=dfn[v]
            if(low[succ]>=dfn[v]){
                cnt++;
                len=0;
                //就不断地将栈顶的边弹出，
                do{
                    in_seq[stack[top]]=cnt;
                    list[len++]=stack[top];
                    top--;
                //直到道弹出边（v,u)为止
                }while(stack[top+1]!=succ);
                //所有弹出的边就构成了双连通分量
                inseq[v]=cnt;
                list[len++]=v;
                vector<int> tmp(list,list+len);
                connect.push_back(tmp);
            }
            low[v]=min(low[v],low[succ]);
        }else low[v]=min(low[v],dfn[succ]);
    }
}
int main(){}

