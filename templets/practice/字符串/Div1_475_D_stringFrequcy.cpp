#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
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

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    int q;
    cin >> q;
    string pat[q];
    int k[q];
    for(int i = 0; i < q; i++){
        cin >> k[i]>> pat[i];
    }
    Aho aho;
    aho.add_paterns(pat,q);
    vector<vector<int>> positions = aho.get_all_occ(s,q);
    for(int i = 0; i < q; i++){
        if(sz(positions[i]) < k[i]) cout << -1 << endl;
        else {
            int ans = 1e9;
            for(int j = 0; j + k[i] - 1 < sz(positions[i]); j++){//暴力枚举k个之间的距离
                ans = min(ans,positions[i][j + k[i] - 1] - positions[i][j] + sz(pat[i]) );
            }
            cout << ans << endl;
        }
    }
}
/* 
题意：给一个串S，q个询问x m_i，询问m_i串出现x次的S的最短子串

对询问串建ac
 */