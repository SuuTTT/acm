#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+10;
char s[maxn];
int leaf[maxn],q[maxn],fail[maxn],tot;
int son[maxn][26];
/* 给定n个模式串和1个文本串，求有多少个模式串在文本串里出现过。 */
void insert(){
  scanf("%s",s);
  for(int l=strlen(s),x=0,i=0,w;i<l;i++){
    if(!son[x][w=s[i]-'a'])son[x][w]=++tot;x=son[x][w];
    if(i==l-1)leaf[x]++;//统计数量
  }
}
void make(){
  int h=1,t=0,i,j,x;fail[0]=-1;
  for(i=0;i<26;i++)if(son[0][i])q[++t]=son[0][i];
  while(h<=t)for(x=q[h++],i=0;i<26;i++)
    if(son[x][i]){
      //leaf[son[x][i]]+=leaf[ fail[son[x][i]]=son[fail[x]][i] ];
      fail[son[x][i]]=son[fail[x]][i];
      q[++t]=son[x][i];
    }else son[x][i]=son[fail[x]][i];
}
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;

	rep(i,1,n)insert();
  make();
  //debug(leaf[0]);
	scanf("%s",s);
	int v=0,ans=0;
	for(int i=0;s[i];i++){//要把所有后缀都统计然后删除叶子标记
 
    v=son[v][s[i]-'a'];
    for(int j=v;j!=-1&&leaf[j]!=0;j=fail[j]){
      ans+=leaf[j];leaf[j]=0;
    }
   
	}
	cout<<ans<<endl;
}
/* 
struct Aho {
    static const int K = 26; //size of alphabet
    struct Vertex {
        int next[K];//trie的指针
        vector<int> matches;//leaf节点，存串的下标
        int p = -1;//祖先
        char pch;//祖先到this的边
        int link = -1; //FDA转移的指针
        int exit_link = -1; //指向输入串尾的link
        int go[K];
        Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
        }
    };
    vector<Vertex> t;
    Aho (){
        t.emplace_back();
    }
    void add_string(string const& s,int id) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].matches.push_back(id);
    }
    void add_paterns(string pat[],int n){//对输入串建trie
        for(int i = 0; i < n; i++)
            add_string(pat[i],i);
    }
    int get_link(int v) {//计算v的suffix link，存在t[v].link
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }
    int get_exit_link(int v){
        if(t[v].exit_link == -1){
        if (v == 0 || t[v].p == 0)
                t[v].exit_link = 0;
            else {
                int link = get_link(v);
                if (link == 0 || sz(t[link].matches))//指向某个串的结尾
                    t[v].exit_link = link;
                else t[v].exit_link = get_exit_link(link);
            }
        }
        return t[v].exit_link;
    }

    int go(int v, char ch) {//v转移到v+c
        int c = ch - 'a';
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
    } 
    vector<int> get_all_matches (int v){//v状态对应的所有模式串及其后缀的下标
        vector<int> ret;
        while(v){
            for(auto id : t[v].matches) ret.pb(id);
            v = get_exit_link(v);
        }
        return ret;
    }
    vector<vector<int>> get_all_occ(string t,int n){//模式串的下标对应文本串中出现的位置。
        vector<vector<int>> occ(n);
        int cur = 0;
        int pos = 0;
        for(auto c : t){
            cur = go(cur,c);
            vector<int> ret = get_all_matches(cur);
            for(auto x : ret) occ[x].pb(pos);
            pos++;
        }
        return occ;
    }

};

 */