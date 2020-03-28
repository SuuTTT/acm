/*
 *  Author : Jk_Chen
 *    Date : 2020-03-15-12.20.03
 * 分层bfs
 */
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define per(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define mmm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pill pair<int, int>
#define fi first
#define se second
#define debug(x) cerr<<#x<<" = "<<x<<'\n'
const LL mod=1e9+7;
const int maxn=5e3+9;
const int inf=0x3f3f3f3f;
LL rd(){ LL ans=0; char last=' ',ch=getchar();
    while(!(ch>='0' && ch<='9'))last=ch,ch=getchar();
    while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
    if(last=='-')ans=-ans; return ans;
}
#define rd rd()
/*_________________________________________________________begin*/

const int di[4][2]={ 1,0,0,1,0,-1,-1,0 };
char M[maxn][maxn];
int dis[maxn][53];
int n,m,k;
int id(int x,int y){
    return x*m+y;
}
struct node{
    int x,y,d;
};
int bfs(){
    pill st,en;
    rep(i,0,n-1)rep(j,0,m-1){
        if(M[i][j]=='A')st.fi=i,st.se=j;
        if(M[i][j]=='B')en.fi=i,en.se=j;
        rep(_,0,k)dis[id(i,j)][_]=inf;
    }

    dis[id(st.fi,st.se)][0]=0;
    queue<node>Q[4];
    int Ze=0;
    Q[Ze].push({st.fi,st.se,0});
    while(1){
        int emp=0;
        while(Q[Ze].empty()&&emp<4){//找到第一个不空的
            emp++;
            Ze=(Ze+1)%4;
        }
        if(emp==4)return -1;
        while(!Q[Ze].empty()){
            node P=Q[Ze].front();Q[Ze].pop();
            if(P.x==en.fi&&P.y==en.se){
                return dis[id(P.x,P.y)][P.d];
            }
            rep(i,0,3){
                int x=P.x+di[i][0];
                int y=P.y+di[i][1];
                if(x<0||x>=n||y<0||y>=m||M[x][y]=='#')continue;
                if(k==1&&M[P.x][P.y]=='D'&&M[x][y]=='D')continue;
                int d;
                int add;
                if(M[x][y]=='.'||M[x][y]=='A'||M[x][y]=='B'){
                    d=P.d;add=1;
                }
                else{
                    if(P.d<k){
                        d=P.d+1;
                        add=2;
                    }
                    else{
                        d=k;
                        add=3;
                    }
                }
                if(dis[id(x,y)][d]>dis[id(P.x,P.y)][P.d]+add){
                    dis[id(x,y)][d]=dis[id(P.x,P.y)][P.d]+add;
                    int to=(Ze+add)%4;
                    Q[to].push({x,y,d});
                }
            }
        }
        Ze=(Ze+1)%4;
    }
}

int main(){
    int t=rd;
    while(t--){
        n=rd,m=rd,k=rd;
        rep(i,0,n-1){
            scanf("%s",M[i]);
        }
        int ans=bfs();
        if(ans==-1){
            puts("HAHAHUHU");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}

/*_________________________________________________________end*/
