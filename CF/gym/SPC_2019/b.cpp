#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define debug(x) cerr<<#x<<": "<<x<<endl
const int inf=0x3f3f3f3f;
typedef long long ll;
const ll mod = (ll)1e9;
int nx[200009],g[200009];
int fx[200009],gg[200009];
int m,n;
int a[200009];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    nx[n]=n;
    for(int i=n-1;i>0;i--){
        if(a[i+1]<a[i])nx[i]=nx[i+1];
        else nx[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(a[i]>=a[i-1]){
            for(int j=i+1;j<=n+1;j++){
                if(j>n||a[j]>=a[j-1]||a[j]<a[i]-a[i-1]+1){
                    g[i]=j-1;
                    break;
                }
            }
        }
    }
    fx[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i-1]<a[i])fx[i]=fx[i-1];
        else fx[i]=i;
    }
    for(int i=n-1;i>0;i--){
        if(a[i]>=a[i+1]){
            for(int j=i-1;j>=0;j--){
                if(j<1||a[j]>=a[j+1]||a[j]<a[i]-a[i+1]+1){
                    gg[i]=j+1;
                    break;
                }
            }
        }
    }
//    for(int i=1;i<=n;i++)printf("%d ",nx[i]);printf("\n");
//    for(int i=1;i<=n;i++)printf("%d ",g[i]);printf("\n");
    while(m--){
        int i1,i2,h1,h2,k;
        scanf("%d%d%d%d%d",&i1,&h1,&i2,&h2,&k);
        int ans;
        if(i1<i2){
            ans=h1+h2+i2-i1;
            if(nx[i1]!=i1){
                if(nx[i1]>=i2){
                    ans=min(ans,a[i1]-h1+a[i2]-h2+i2-i1);//printf("1:%d\n",ans);
                    if(i2-i1>1)ans=min(ans,a[i1]-h1+i2-i1+h2+a[i2-1]-min(k,a[i2-1]));//printf("2:%d\n",ans);
                }
                else{
                    ans=min(ans,a[i1]-h1+i2-i1+h2+a[nx[i1]]-min(k,a[nx[i1]]));//printf("3:%d\n",ans);
                    if(nx[i1]+1<i2&&a[nx[i1]+1]-min(k,a[nx[i1]+1])<a[nx[i1]]){
                        if(g[nx[i1]+1]>=i2){
                            ans=min(ans,a[i1]-h1+i2-i1+h2+a[i2-1]-min(k,a[i2-1]));//printf("4:%d\n",ans);
                            if(a[i2-1]-(a[nx[i1]+1]-a[nx[i1]]+1)>a[i2])ans=min(ans,a[i1]-h1+a[i2]-h2+i2-i1);//printf("5:%d\n",ans);
                        }
                        else{
                            ans=min(ans,a[i1]-h1+i2-i1+h2+a[g[nx[i1]+1]]-min(k,a[g[nx[i1]+1]]));//printf("6:%d\n",ans);
                        }
                    }
                }
            }
        }
        else{
            ans=h1+h2+i1-i2;
            if(fx[i1]!=i1){
                if(fx[i1]<=i2){
                    ans=min(ans,a[i1]-h1+a[i2]-h2+i1-i2);//printf("1:%d\n",ans);
                    if(i1-i2>1)ans=min(ans,a[i1]-h1+i1-i2+h2+a[i2+1]-min(k,a[i2+1]));//printf("2:%d\n",ans);
                }
                else{
                    ans=min(ans,a[i1]-h1+i1-i2+h2+a[fx[i1]]-min(k,a[fx[i1]]));//printf("3:%d\n",ans);
                    if(fx[i1]-1>i2&&a[fx[i1]-1]-min(k,a[fx[i1]-1])<a[fx[i1]]){
                        if(gg[fx[i1]-1]<=i2){
                            ans=min(ans,a[i1]-h1+i1-i2+h2+a[i2+1]-min(k,a[i2+1]));//printf("4:%d\n",ans);
                            if(a[i2+1]-(a[fx[i1]-1]-a[fx[i1]]+1)>a[i2])ans=min(ans,a[i1]-h1+a[i2]-h2+i1-i2);//printf("5:%d\n",ans);
                        }
                        else{
                            ans=min(ans,a[i1]-h1+i1-i2+h2+a[gg[fx[i1]-1]]-min(k,a[gg[fx[i1]-1]]));//printf("6:%d\n",ans);
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
Input

10 10
4 2 3 3 11 5 4 3 15 3
8 3 2 0 1
8 3 7 0 3
3 3 8 0 4
2 2 9 0 5
10 3 6 0 3
4 3 5 0 2
9 15 1 0 2
6 5 2 0 6
1 4 4 0 2
6 5 9 0 4

Output

9
4
8
9
7
4
9
9
3
3

Answer

9
4
6
8
7
4
9
7
4
4


6 4
10 9 8 10 9 6
1 10 6 5 4
6 5 1 10 4
1 10 6 5 4
1 10 6 5 4
*/