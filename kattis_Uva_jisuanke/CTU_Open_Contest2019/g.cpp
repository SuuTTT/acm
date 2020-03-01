#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<": "<<x<<endl
typedef long long ll;
const ll mod = (ll)1e9+7;
int n;
char s[300009];
int qian[300009],hou[300009];
int la[1100009];
int main()
{
    scanf("%d%s",&n,s+1);
    qian[0]=0;
    for(int i=1;i<=n;i++){
        qian[i]=qian[i-1]^(1<<(s[i]-'a'));
    }
    hou[n+1]=0;
    for(int i=n;i>=1;i--){
        hou[i]=hou[i+1]^(1<<(s[i]-'a'));
    }

    for(int i=n+1;i>=1;i--){
        if(la[hou[i]]==0)la[hou[i]]=i;
    }
    int all=qian[n];
    int ans=0;
    for(int i=0;i<n;i++){
        int res=all^qian[i];
        if(la[res]){
            ans=max(ans,la[res]-i-1);
        }
        for(int j=0;j<20;j++){
            res=all^qian[i]^(1<<j);
            if(la[res]){
                ans=max(ans,la[res]-i-1);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}