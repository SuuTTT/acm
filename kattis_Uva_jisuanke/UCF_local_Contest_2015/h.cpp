#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
char s[15][15];
int vis[15][15],c[15][15];
int T,m,n;
void print(){
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)printf("%d ",vis[i][j]);printf("\n");
    }
}
int main(){
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
            for(int j=0;j<m;j++)vis[i][j]=c[i][j]=0;
        }
        int ans=0,flag=1;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(s[i][j]=='#'&&s[i-1][j]=='#'&&s[i+1][j]=='#'&&s[i][j-1]=='#'&&s[i][j+1]=='#'){
                    vis[i][j]++;vis[i-1][j]++;vis[i+1][j]++;vis[i][j-1]++;vis[i][j+1]++;
                    c[i][j]=c[i-1][j]=c[i+1][j]=c[i][j-1]=c[i][j+1]=1;
                }
            }
        }
        //print();
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(vis[i][j]>1&&vis[i-1][j]>1&&vis[i+1][j]>1&&vis[i][j-1]>1&&vis[i][j+1]>1){
                    vis[i][j]--;vis[i-1][j]--;vis[i+1][j]--;vis[i][j-1]--;vis[i][j+1]--;
                }
            }
        }
        //print();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='#'&&c[i][j]==0)flag=0;
                if(i>0&&i<n-1&&j>0&&j<m-1){
                    if(vis[i][j]&&vis[i-1][j]&&vis[i+1][j]&&vis[i][j-1]&&vis[i][j+1]){
                        vis[i][j]--;vis[i-1][j]--;vis[i+1][j]--;vis[i][j-1]--;vis[i][j+1]--;
                        ans++;
                    }
                    //print();
                }
            }
        }
        if(cas!=1)printf("\n");
        if(!flag)printf("Image #%d: impossible\n",cas);
        else printf("Image #%d: %d\n",cas,ans);
    }

    return 0;
}
/*
9 9
.#######.
#########
#########
#########
#########
#########
#########
#########
.#######.
*/

/* 

 */