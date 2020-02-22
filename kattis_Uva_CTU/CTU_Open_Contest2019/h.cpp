#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<": "<<x<<endl
typedef long long ll;
const ll mod = (ll)1e9+7;
struct Animal{
    int type,life;
};
struct Ground{
    int type,time;
};
struct node{
    Ground g;
    Animal a[2];
    int has;
}w[30][30],res[30][30];
int t;
int n,m;
char start[30][30],ans[30][30];
void Move(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            res[i][j]=w[i][j];
            res[i][j].has=0;
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int fi=(i+n-1)%n;
            if(w[fi][j].has>0&&w[fi][j].a[0].type==1){
                res[i][j].a[res[i][j].has++]=w[fi][j].a[0];
            }
            int fj=(j+m-1)%m;
            if(w[i][fj].has>0&&w[i][fj].a[0].type==2){
                res[i][j].a[res[i][j].has++]=w[i][fj].a[0];
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            w[i][j]=res[i][j];
        }
}
void eat(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(w[i][j].has>1){
                w[i][j].has=1;
                w[i][j].a[0].type=2;w[i][j].a[0].life=11;
                w[i][j].g.type=2;w[i][j].g.time=0;
            }
            else if(w[i][j].has&&w[i][j].a[0].type==1&&w[i][j].g.type==1){
                w[i][j].a[0].life=6;
                w[i][j].g.type=0;w[i][j].g.time=-1;
            }
        }
    }
}
void starvation(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(w[i][j].has){
                w[i][j].a[0].life--;
                if(w[i][j].a[0].life==0){
                    w[i][j].has=0;
                    w[i][j].g.type=2;w[i][j].g.time=0;
                }
            }
        }
    }
}
void grow(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            w[i][j].g.time++;
            if(w[i][j].g.time==3&&w[i][j].g.type==0){w[i][j].g.type=1;w[i][j].g.time=0;}
        }
    }
}
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(w[i][j].has){
                if(w[i][j].a[0].type==1)ans[i][j]='S';
                else ans[i][j]='W';
            }
            else {
                if(w[i][j].g.type==0)ans[i][j]='.';
                else if(w[i][j].g.type==1)ans[i][j]='#';
                else ans[i][j]='*';
            }
        }
        ans[i][m]='\0';
        printf("%s\n",ans[i]);
    }
}
void go(){
    Move();
    eat();
    starvation();
    grow();
}
int main()
{
    scanf("%d%d%d",&t,&n,&m);
    for(int i=0;i<n;i++)scanf("%s",start[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            w[i][j].g.type=0;w[i][j].g.time=0;
            if(start[i][j]=='.')w[i][j].has=0;
            else if(start[i][j]=='S'){
                w[i][j].has=1;
                w[i][j].a[0].type=1;w[i][j].a[0].life=5;
            }
            else {
                w[i][j].has=1;
                w[i][j].a[0].type=2;w[i][j].a[0].life=10;
            }
        }
    }
    while(t--)go();
    print();

    return 0;
}