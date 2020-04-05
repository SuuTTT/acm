#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
const int K = 26;
typedef long long ll;
const ll mod=1000003;
ll f[30][10000][2][2][2];
void add(ll &x,ll y){
    x+=y;
    if(x>=mod)x-=mod;
}
struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;//祖先
    char pch;//祖先到this的边
    int link = -1;
    int go[K];//每个字母对应的transition
 
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};
 
vector<Vertex> t(1);
 
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}
 
int go(int v, char ch);//v转移到v+c
 
int get_link(int v) {//计算v的suffix link，存在t[v].link
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch),t[v].leaf|=t[t[v].link].leaf;
    }
    return t[v].link;
}
 
int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}
 
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,n;
    cin>>a>>b>>n;
    rep(i,1,n){string s;cin>>s;add_string(s);}
    //debug(t.size());
    rep(j,0,t.size())rep(c,'a','z') go(j,c);
    f[0][0][0][0][0]=1;
    rep(i,0,b)rep(j,0,t.size())rep(l,0,1)rep(u,0,1)rep(d,0,1){
        if(f[i][j][l][u][d]==0)continue;
        rep(c,'a','z'){
            int v=go(j,c);
            if(t[v].leaf)continue;
            add(f[i+1][v][1][u][d],f[i][j][l][u][d]);
            add(f[i+1][v][l][1][d],f[i][j][l][u][d]);
        }
        rep(c,0,9){//0 ('o'), 1 ('i'), 3 ('e'), 5 ('s') and 7 ('t')
            int v=0;
            if(c==0)v=go(j,'o');
            if(c==1)v=go(j,'i');
            if(c==3)v=go(j,'e');
            if(c==5)v=go(j,'s');
            if(c==7)v=go(j,'t');
            if(t[v].leaf)continue;
            add(f[i+1][v][l][u][1],f[i][j][l][u][d]);
        }
    }
    ll ans=0;
    rep(i,a,b)rep(j,0,t.size())add(ans,f[i][j][1][1][1]);
    cout<<ans<<endl;
}
/* 
E：满足长度在AB之间，同时有大小写和数字的串的个数。且没有子串在给定字典里出现，匹配时0 ('o'), 1 ('i'), 3 ('e'), 5 ('s') and 7 ('t')可以替换。模1 000 003
3 5
9
swerc
icpc
fbi
cia
bio
z
hi
no
yes
 
*/