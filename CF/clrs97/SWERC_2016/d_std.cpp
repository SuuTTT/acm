#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<time.h>
#include<assert.h>
#include<iostream>
using namespace std;
typedef long long LL;
typedef pair<int,int>pi;
int n,d,ned;
int idx[55];
int cnt[3];
double dp[12][12][12];
LL C[100][100];
double dfs(int a0,int a1,int a2){
    double &t=dp[a0][a1][a2];
    if(t>-0.5)return t;
    if(a0+a2>=ned||a1+a2>=ned)return t=0;
    double tmp=1;
    double nedp;
    for(int ad0=0;ad0+a0<=cnt[0];ad0++)
    for(int ad1=0;ad1+a1<=cnt[1];ad1++)
    for(int ad2=0;ad2+a2<=cnt[2];ad2++){
        if(ad0+ad1+ad2>d)continue;
        double p=(
            C[n-(cnt[0]-a0)-(cnt[1]-a1)-(cnt[2]-a2)][d-ad0-ad1-ad2]*
            C[(cnt[0]-a0)][ad0]*
            C[(cnt[1]-a1)][ad1]*
            C[(cnt[2]-a2)][ad2]+0.0)/C[n][d];
        if(!ad0&&!ad1&&!ad2)nedp=p;
        else{
            dfs(a0+ad0,a1+ad1,a2+ad2);
            tmp+=p*dp[a0+ad0][a1+ad1][a2+ad2];
        }
    }
    t=tmp/(1-nedp);
//  printf("a0=%d a1=%d a2=%d dp=%.2f ned=%d\n",a0,a1,a2,t,ned);
    return t;
}
int main(){
    for(int i=0;i<=50;i++)C[i][0]=1;
    for(int i=1;i<=50;i++){
        for(int j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    while(scanf("%d%d%d",&n,&d,&ned)!=EOF){
        memset(idx,0,sizeof idx);
        memset(cnt,0,sizeof cnt);
        for(int i=0;i<2;i++){
            for(int j=0;j<ned;j++){
                int x;scanf("%d",&x);
                idx[x]|=1<<i;
            }
        }
        for(int i=1;i<=n;i++)if(idx[i])cnt[idx[i]-1]++;
        memset(dp,-1,sizeof dp);
        dfs(0,0,0);
        printf("%.12f\n",dp[0][0][0]);
    }
    return 0;
}