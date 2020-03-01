#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<": "<<x<<endl
typedef long long ll;
const ll mod = (ll)1e9+7;
int n,m,k;
int c,r,v;
ll w[100009][2];
ll dp[19][19],la[19][19];

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0;i<n;i++)w[i][0]=w[i][1]=-1;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&c,&r,&v);
        w[c][r]=v;
    }
    ll a[19],b[19];
    for(int i=0;i<19;i++)a[i]=b[i]=0;
    for(int i=0;i<=9;i++){
        if(w[0][0]>=0&&w[0][0]!=i)continue;
        for(int j=0;j<=9;j++){
            if(w[0][1]>=0&&w[0][1]!=j)continue;
            a[i+j]++;
        }
    }
    for(int i=0;i<=9;i++){
        if(w[1][0]>=0&&w[1][0]!=i)continue;
        for(int j=0;j<=9;j++){
            if(w[1][1]>=0&&w[1][1]!=j)continue;
            b[i+j]++;
        }
    }
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++)la[i][j]=a[i]*b[j];
    }
    for(int i=2;i<n;i++){
        for(int j=0;j<19;j++){
            int has=0,sum=0;
            if(w[i][0]>=0)has++,sum+=w[i][0];
            if(w[i][1]>=0)has++,sum+=w[i][1];
            if(has==0){
                for(int g=0;g<19;g++){
                    if(j+g+18<k||j+g>k)dp[j][g]=0;
                    else if(g<10)dp[j][g]=la[k-j-g][j]*(g+1)%mod;
                    else dp[j][g]=la[k-j-g][j]*(19-g)%mod;
                }
            }
            else if(has==1){
                for(int g=0;g<19;g++){
                    if(j+g+18<k||j+g>k)dp[j][g]=0;
                    else if(sum>g||sum+9<g)dp[j][g]=0;
                    else dp[j][g]=la[k-j-g][j];
                }
            }
            else {
                for(int g=0;g<19;g++){
                    if(j+g+18<k||j+g>k)dp[j][g]=0;
                    else if(g!=sum)dp[j][g]=0;
                    else dp[j][g]=la[k-j-g][j];
                }
            }
        }
        for(int j=0;j<19;j++)
            for(int g=0;g<19;g++)la[j][g]=dp[j][g];
    }
    ll ans=0;
    for(int i=0;i<19;i++)
        for(int j=0;j<19;j++)ans=(ans+dp[i][j])%mod;
    printf("%lld\n",ans);
    return 0;
}