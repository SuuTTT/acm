#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n;
int vis[1000009];
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        char x;
        int res=0;
        while((x=getchar())!='\n'){
            if(x<'0'||x>'9')res=2000000;
            if(res<2000000)res=res*10+x-'0';
        }
        if(res<=1000000)vis[res]=1;
    }
    for(int i=0;i<=n;i++){
        if(vis[i]==0){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
/*

*/