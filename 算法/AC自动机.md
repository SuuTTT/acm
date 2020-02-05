

## 构建fail

1、刚开始我们不是要初始化第一层的fail指针为root，其实我们可以建一个虚节点0号节点，将0的所有儿子指向root（编号为1)，然后root的fail指向0就OK了。效果是一样的。

2、如果不存在一个节点i，那么我们可以将那个节点设为fafail的值（想表达：儿子中？？？）和i相同的儿子。保证存在性，就算是0也可以成功返回到根，因为0的所有儿子都是根。

3、无论fafail存不存在和i值相同的儿子j，我们都可以将i的fail指向j。因为在处理i的时候j已经处理好了，如果出现这种情况，j的值是第2种情况，也是有实际值的，所以没有问题。

4、实现时不记父亲，我们直接让父亲更新儿子

```c++
void getFail(){
    for(int i=0;i<26;i++)trie[0].son[i]=1;          //初始化0的所有儿子都是1
    q.push(1);trie[1].fail=0;               //将根压入队列
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<26;i++){              //遍历所有儿子
            int v=trie[u].son[i];           //处理u的i儿子的fail，这样就可以不用记父亲了
            int Fail=trie[u].fail;          //就是fafail，trie[Fail].son[i]就是和v值相同的点
            if(!v){trie[u].son[i]=trie[Fail].son[i];continue;}  //不存在该节点，第二种情况
            trie[v].fail=trie[Fail].son[i]; //第三种情况，直接指就可以了
            q.push(v);                      //存在实节点才压入队列
        }
    }
}
```

## 查询

查询文本串中有几种不同模式串。

为了避免重复计算，我们每经过一个点就打个标记为-1，下一次经过就不重复计算了。

同时，如果一个字符串匹配成功，那么他的Fail也肯定可以匹配成功（后缀嘛），于是我们就把Fail再统计答案，同样，Fail的Fail也可以匹配成功，以此类推……经过的点累加flag，标记为-1。

最后主要还是和Trie的查询是一样的。

```c++
int query(char* s){
    int u=1,ans=0,len=strlen(s);
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        int k=trie[u].son[v];       //跳Fail
        while(k>1&&trie[k].flag!=-1){   //经过就不统计了
            ans+=trie[k].flag,trie[k].flag=-1;  //累加上这个位置的模式串个数，标记 已 经过
            k=trie[k].fail;         //继续跳Fail
        }
        u=trie[u].son[v];           //到儿子那,存在性看上面的第二种情况
    }
    return ans;
}
```

## 插入

和Trie的插入是一样的。

```c++
void insert(char* s){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        if(!trie[u].son[v])trie[u].son[v]=++cnt;
        u=trie[u].son[v];
    }
    trie[u].flag++;
}
```



## 例题

## P3808 【模板】AC自动机（简单版）

题意：询问文本串中有几种不同模式串。

```c++
int main(){
    cnt=1;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        insert(s);
    }
    getFail();
    scanf("%s",s);
    printf("%d\n",query(s));
    return 0;
}
```

[**P3796** 【模板】AC自动机（加强版）](https://www.luogu.org/problemnew/show/P3796)

题意：问文本串中出现次数最多的模式串。

插入：我们将标记模式串的flag设为当前是第几个模式串。就是给它标一个id：

```c++
trie[u].flag++;
变为
trie[u].flag=num; //num表示该字符串是第num个输入的
```

查询：我们每经过一个点，如果有模式串标记，就将vis[模式串标记]++，注意我们是统计每个模式串的次数，所以不能将其flag更新成-1。

```c++
  while(k>1){   
            if(trie[k].flag)vis[trie[k].flag]++,Ans=max(Ans,vis[trie[k].flag]);  //flag不赋值为-1了
            k=trie[k].fail;         //继续跳Fail
        }
```



初始化：定义clear函数

```c++
struct kkk{
    int son[26],flag,fail;
    void clear(){memset(son,0,sizeof(son));flag=fail=0;}
}trie[maxn];
void init(){
    rep(i,0,cnt)trie[i].clear();
    rep(i,0,n)vis[i]=0;
    cnt=1;Ans=0;
    num=0;
}
```

[**P5357** 【模板】AC自动机（二次加强版）](https://www.luogu.org/problemnew/show/P5357)

由于把打标记的操作删除了，上面的代码复杂度为 O(模式串长度 · 文本串长度)。



topo建图优化

首先是getfail这里，记得将fail的入度更新。

```c++
trie[v].fail=trie[Fail].son[i]; in[trie[v].fail]++;     //记得加上入度
```

然后是query，不用暴力跳fail了，直接打上标记就行了，很简单吧

```c++
void query(char* s){
    int u=1,len=strlen(s);
    for(int i=0;i<len;++i)
    u=trie[u].son[s[i]-'a'],trie[u].ans++;                          //直接打上标记
}
```

最后是拓扑，

```c++
void topu(){
    for(int i=1;i<=cnt;++i)
    if(in[i]==0)q.push(i);              //将入度为0的点全部压入队列里
    while(!q.empty()){
        int u=q.front();q.pop();vis[trie[u].flag]=trie[u].ans;  //如果有flag标记就更新vis数组
        int v=trie[u].fail;in[v]--;     //将唯一连出去的出边fail的入度减去（拓扑排序的操作）
        trie[v].ans+=trie[u].ans;       //更新fail的ans值
        if(in[v]==0)q.push(v);          //拓扑排序常规操作
    }
}
```



完整代码：

```c++
#include<bits/stdc++.h>
#define maxn 2000001
using namespace std;
char s[maxn],T[maxn];
int n,cnt,vis[200051],ans,in[maxn],Map[maxn];
struct kkk{
    int son[26],fail,flag,ans;
}trie[maxn];
queue<int>q;
void insert(char* s,int num){
    int u=1,len=strlen(s);
    for(int i=0;i<len;++i){
        int v=s[i]-'a';
        if(!trie[u].son[v])trie[u].son[v]=++cnt;
        u=trie[u].son[v];
    }
    if(!trie[u].flag)trie[u].flag=num;
    Map[num]=trie[u].flag;
}
void getFail(){
    for(int i=0;i<26;i++)trie[0].son[i]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        int Fail=trie[u].fail;
        for(int i=0;i<26;++i){
            int v=trie[u].son[i];
            if(!v){trie[u].son[i]=trie[Fail].son[i];continue;}
            trie[v].fail=trie[Fail].son[i]; in[trie[v].fail]++;
            q.push(v);
        }
    }
}
void topu(){
    for(int i=1;i<=cnt;++i)
    if(in[i]==0)q.push(i);              //将入度为0的点全部压入队列里
    while(!q.empty()){
        int u=q.front();q.pop();vis[trie[u].flag]=trie[u].ans;  //如果有flag标记就更新vis数组
        int v=trie[u].fail;in[v]--;     //将唯一连出去的出边fail的入度减去（拓扑排序的操作）
        trie[v].ans+=trie[u].ans;       //更新fail的ans值
        if(in[v]==0)q.push(v);          //拓扑排序常规操作
    }
}
void query(char* s){
    int u=1,len=strlen(s);
    for(int i=0;i<len;++i)
    u=trie[u].son[s[i]-'a'],trie[u].ans++;
}
int main(){
    scanf("%d",&n); cnt=1;
    for(int i=1;i<=n;++i){
        scanf("%s",s);
        insert(s,i);
    }getFail();scanf("%s",T);
    query(T);topu();
    for(int i=1;i<=n;++i)printf("%d\n",vis[Map[i]]);
}
```

