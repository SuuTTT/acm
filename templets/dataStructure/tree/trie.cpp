/* 
插入一个字符串，查询串是否存在。
O(|S|)

child[i][j]代表以i为根的子树，j代表的边连向哪个节点。
flag[i]代表是否为一个单词的结尾。
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
/* 
模板：用char[]，所以用到指针。
另外 *cur=&root的操作很迷，没必要？？

http://poj.org/problem?id=1056
insert加了一下两个flag，用来判是否是1.是别人的前缀。2.别人是自己的前缀。

 */
const int CHARSET=26,BASE='0',MAX_NODE=100000;
struct Trie{
    int tot,root,child[MAX_NODE][CHARSET];
    bool flag[MAX_NODE];
    void trie(){
        memset(child[1],0,sizeof(child[1]));
        flag[1]=0;
        root=tot=1;
    }
    bool insert(const char *str){
        bool f1=0,f2=1;
        int *cur=&root;
        for(const char *p=str;*p;++p){
            cur=&child[*cur][*p-BASE];
            if(flag[*cur])f1=1;
            if(*cur==0){
                f2=0;
                *cur=++tot;
                memset(child[tot],0,sizeof(child[tot]));
                flag[tot]=0;
            }
        }
        flag[*cur]=1;
        return f1||f2;
    }
    bool query(const char *str){
        int *cur=&root;
        for(const char *p=str;*p&& *cur;++p)
            cur=&child[*cur][*p-BASE];
        return (*cur && flag[*cur]);
    }
}tr;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    int kase=1;
    int flag=1;
    int cnt=0;
    tr.trie();
    while(cin>>s){
        cnt++;
        if(s[0]=='9'){
            if(cnt<2)flag=0;
            cout<<"Set "<<kase++<<' ';
            cout<<(flag?"is immediately decodable":
            "is not immediately decodable")<<endl;
            tr.trie();
            flag=1;
            cnt=0;
        }
        else{
            if(tr.insert(s.c_str())) flag=0;
            
        }
        
    }
}
/* 
01
10
0010
0000
9
01
10
010
0000
9
 */

