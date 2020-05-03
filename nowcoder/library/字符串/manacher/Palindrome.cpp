#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef __int128_t ll;
const int maxn = 4e5+100;
char s[maxn];
char t[maxn];
long long n;
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    //extension
    int cntA[maxn*2],A[maxn*2];/*辅助拓扑更新*/
    int nums[maxn*2],numt[maxn*2];/*每个节点代表的所有串的出现次数*/
    int weights[maxn*2],weightt[maxn*2];
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        while (*s){
            add(*s-'a');
            s++;
        }
    }
    void add(int c){
        int p = last;
        int np = ++cnt;
        memset(nxt[cnt],0,sizeof nxt[cnt]);
        l[np] = l[p]+1;
        last = np;
        while (p&&!nxt[p][c])nxt[p][c] = np,p = fa[p];
        if (!p)fa[np]=1;
        else{
            int q = nxt[p][c];
            if (l[q]==l[p]+1)fa[np] =q;
            else{
                int nq = ++ cnt;
                l[nq] = l[p]+1;
                memcpy(nxt[nq],nxt[q],sizeof (nxt[q]));
                fa[nq] =fa[q];
                fa[np] = fa[q] =nq;
                while (nxt[p][c]==q)nxt[p][c] =nq,p = fa[p];
            }
        }
    }
    void build(){
        //memset(cntA,0,sizeof cntA);
        //memset(nums,0,sizeof nums);
        //memset(numt,0,sizeof numt);
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=n;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
        /*更行主串节点*/
        int temps=1,tempt = 1;
        for (int i=1;i<=n;i++){
            nums[temps = nxt[temps][s[i]-'a'] ]=1;
            numt[tempt = nxt[tempt][t[i]-'a']] = 1;
        }
        /*拓扑更新*/
        for (int i=cnt;i>=1;i--){
            //basic
            int x = A[i];
            nums[fa[x]]+=nums[x];
            numt[fa[x]] += numt[x];
        }
    }
  
    void debug(){
        for (int i=cnt;i>=1;i--){
            printf("nums[%d]=%d numt[%d]=%d l[%d]=%d fa[%d]=%d\n",i,nums[i],i,numt[i],i,l[i],i,fa[i]);
        }
    }
  
    ll query(){
        ll res = 0;
        for (int i=1;i<=cnt;i++){
            res += 1LL*nums[i] * numt[i] * (l[i] - l[fa[i]]);
        }
        return res;
    }
    ll query2(){
        ll res = 0;
        for (int i=1;i<=cnt;i++){
            res += 1LL*weights[i] * numt[i] *(l[i] - l[fa[i]]);
            res += 1LL*weightt[i] * nums[i] *(l[i] - l[fa[i]]);
        }
        return res;
    }
}sam;
struct Manacher{
    char ch[maxn*2];
    int lc[maxn*2];
    int N;
    void init(const char *s){
        N = 2*n+1;
        ch[N] = '#';
        for (int i=n;i>=1;i--){
            ch[i*2] = s[i];
            ch[i*2-1] = '#';
        }
        ch[0] = 'z'+1;
        ch[N+1] = '\0';
        manacher();
    }
    void manacher(){
        lc[1] = 1;
        int k = 1;
        for (int i=2;i<=N;i++){
            int p = k + lc[k] -1;
            if (i <= p){
                lc[i] = min(lc[2*k-i],p-i+1);
            }else{
                lc[i] = 1;
            }
            while (ch[i+lc[i]] == ch[i-lc[i]])lc[i] ++;
            if (i+lc[i] > k+lc[k]) k = i;
        }
    }
    int query(int x){
        return lc[x]>>1;
    }
    void debug(){
        for (int i=1;i<=N;i++){
            printf("lc[%d]=%d\n",i,lc[i]);
        }
    }
}mas,mat;
struct Prefix_Sum{
    ll val[maxn*2];
    void clear(){
        memset(val,0,sizeof val);
    }
    void add(int l,int r,int delta){
        val[l] += delta;
        val[r+1] -= delta;
    }
    void build(){
        //val[0] = 0;
        for (int i=1;i<maxn;i++){
            val[i] += val[i-1];
        }
    }
    ll query(int x){
        return val[x];
    }
    void debug(){
        for (int i=1;i<=n;i++){
            printf("val[%d]=%d\n",i,val[i]);
        }
    }
}sums,sumt;
ll calc(){
    mas.init(s);
    mat.init(t);
    //mas.debug();
    //mat.debug();
    //sums.clear();
    //sumt.clear();
    for (int i=1;i<=n;i++){
        sums.add(i-mas.query(i<<1),i-1,1);
        sumt.add(i-mat.query(i<<1),i-1,1);
        sums.add(i-mas.query(i<<1|1),i-1,1);
        sumt.add(i-mat.query(i<<1|1),i-1,1);
        //printf("lcs[%d]=%d lct[%d]=%d\n",i,mas.query(i),i,mat.query(i));
    }
    sums.build();
    sumt.build();
    //sums.debug();
    //sumt.debug();
    int temps = 1;
    int tempt = 1;
    for (int i=1;i<=n;i++){
        temps = sam.nxt[temps][s[i] - 'a'];
        tempt = sam.nxt[tempt][t[i] - 'a'];
        sam.weights[temps] += sums.query(i);
        sam.weightt[tempt] += sumt.query(i);
    }
    for (int i=sam.cnt;i>=1;i--){
        //basic
        int x = sam.A[i];
        sam.weights[sam.fa[x]]+=sam.weights[x];
        sam.weightt[sam.fa[x]]+=sam.weightt[x];
    }
    return sam.query2();
}
template <class T>
void print(T a)
{
    if (a>9) print(a/10);
    putchar(a%10+'0');
}
signed main(){
    scanf("%lld",&n);
    scanf("%s",s+1);
    memcpy(t,s,sizeof t);
    reverse(t+1,t+n+1);
    //cout<<s+1<<" "<<t+1<<endl;
    sam.clear();
    sam.init(s+1);
    sam.last = 1;
    sam.init(t+1);
    sam.build();
    ll ans = sam.query();
    //sam.debug();
    //cout<<ans<<endl;
    ans += calc();
    print(ans);
    return 0;
}
/* 
从s中选择两个非空子串a,b（可以有重叠的部分），使得它们拼起来是一个回文串。

SAM+manacher
exkmp+manacher
SAM+pam
 */