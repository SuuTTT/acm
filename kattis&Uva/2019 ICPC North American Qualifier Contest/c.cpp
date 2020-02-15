#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
struct dis{
    int a,b;
}D[maxn];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int p,d;
    cin>>p>>d;
    rep(i,1,p){
        int x,y,z;
        cin>>x>>y>>z;
        D[x].a+=y;
        D[x].b+=z;
    }
    double wa=0,wb=0,v=0;;
    rep(i,1,d){
        int win=D[i].a+D[i].b;
        win=win/2+1;
        //debug(i),debug(win);
        int flag=D[i].a>=win?1:0;
        int tmpa=0,tmpb=0;
        if(flag){
            tmpa=D[i].a-win,tmpb=D[i].b;
        }
        else{
            tmpb=D[i].b-win,tmpa=D[i].a;
        }
        wa+=tmpa;
        wb+=tmpb;
        v+=D[i].a+D[i].b;
        cout<<(flag?"A":"B")<<' '<<tmpa<<' '<<tmpb<<endl;;
    }
    printf("%.20lf",abs(wa-wb)/v);
}
/* 
5 3
1 100 200
2 100 99
3 100 50
3 100 50
2 100 98
 */