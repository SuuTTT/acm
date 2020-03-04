#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
const int inf=0x3f3f3f3f;
int t;
int n;
int a[59],b[59];
int dp[59][59];
int sum[59],mx[59][59];
int main(){
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
        sum[0]=0;
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
        for(int i=1;i<=n;i++){
            mx[i][i]=b[i];
            for(int j=i+1;j<=n;j++){
                mx[i][j]=max(mx[i][j-1],b[j]);
            }
        }
        for(int i=1;i<=n;i++)dp[i][i]=0;
        for(int len=1;len<n;len++){
            for(int s=1;s+len<=n;s++){
                dp[s][s+len]=100000000;
                for(int i=s;i<s+len;i++){
                    int l1,d1,l2,d2;
                    l1=sum[i]-sum[s-1];
                    d1=mx[s][i];
                    l2=sum[s+len]-sum[i];
                    d2=mx[i+1][s+len];
                    dp[s][s+len]=min(dp[s][s+len],dp[s][i]+dp[i+1][s+len]+100*min(l1,d1)*min(l2,d2));
                }
            }
        }
        printf("The minimum cost for lot #%d is $%d.\n\n",cas,dp[1][n]);
    }
    return 0;
}
/*

*/
