#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;

const int N=1010,P=1000003;
int A,B,tot,son[N][26],fail[N],q[N],ban[N],ans,i,j,x,y,z,t,o;
int n;char s[N];
int f[22][N][2][2][2];//串长为i，目前走到了j这个点 lower upper digit
inline void add(int&x,int y){
  x+=y;
  if(x>=P)x-=P;
}
void insert(){
  scanf("%s",s);
  for(int l=strlen(s),x=0,i=0,w;i<l;i++){
    if(!son[x][w=s[i]-'a'])son[x][w]=++tot;x=son[x][w];
    if(i==l-1)ban[x]=1;
  }
}
void make(){
  int h=1,t=0,i,j,x;fail[0]=-1;
  for(i=0;i<26;i++)if(son[0][i])q[++t]=son[0][i];
  while(h<=t)for(x=q[h++],i=0;i<26;i++)
    if(son[x][i]){
      ban[son[x][i]]|=ban[ fail[son[x][i]]=son[fail[x]][i] ];//如果某串的后缀被ban，那它自己也被ban。
      q[++t]=son[x][i];
    }else son[x][i]=son[fail[x]][i];
}

int go(int x,char c){
    return son[x][c-'a'];
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,n;
    cin>>a>>b>>n;
    rep(i,1,n){insert();}
    make();
    f[0][0][0][0][0]=1;
    //for v for c
    rep(i,0,b)rep(j,0,tot)rep(l,0,1)rep(u,0,1)rep(d,0,1){
        if(f[i][j][l][u][d]==0)continue;
        rep(c,'a','z'){
            int v=go(j,c);
            if(ban[v])continue;
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
            if(ban[v])continue;
            add(f[i+1][v][l][u][1],f[i][j][l][u][d]);
        }
    }
    int ans=0;
    rep(i,a,b)rep(j,0,tot)add(ans,f[i][j][1][1][1]);
    cout<<ans<<endl;
}

/* 
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