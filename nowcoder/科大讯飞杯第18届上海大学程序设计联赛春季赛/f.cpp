#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<(x)<<endl
const int maxn=(int)1e6+5;

int zeller(int y,int m,int d){
    int c=y/100;
    y=y%100;
    int ret=c/4-2*c+y+y/4+13*(m+1)/5+d-1;
    ret%=7;ret+=7;ret%=7;
    return ret;
}
vector<int> date;
void init(){
    rep(i,2000,2101){
        int cur=zeller(i,5,1);
        int cnt=0;
        rep(j,1,15){
            if((cur+j-1)%7==0)cnt++;
            if(cnt==2){date.push_back(i*10000+5*100+j);break;}
        }
        cur=zeller(i,6,1);
        cnt=0;
        rep(j,1,22){
            if((cur+j-1)%7==0)cnt++;
            if(cnt==3){date.push_back(i*10000+6*100+j);break;}
        }
    }
}
char s[5];
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //debug(zeller(1994,12,13));
    init();
    int t;cin>>t;
    while(t--){
        int y,m,d;cin>>y>>m>>d;
        int tmp=*upper_bound(date.begin(),date.end(),y*10000+m*100+d);
        //debug(tmp);
        y=tmp/10000;
        m=tmp/100%100;
        d=tmp%100;
        
        s[0]='t',s[1]='h';
        if(d>20){
            if(d%10==1)s[0]='s',s[1]='t';
        if(d%10==2)s[0]='n',s[1]='d';
        if(d%10==3)s[0]='r',s[1]='d';
        }
        
        
        if(m==5){
            printf("Mother's Day: May %d%s, %d\n",d,s,y);
        }else printf("Father's Day: June %d%s, %d\n",d,s,y);
    }
}
/* 
T==100
100*365 baoli
7
2000 1 1
2001 1 1
2002 1 1
2003 1 1
2020 1 1
2020 5 10
2020 6 21
 */