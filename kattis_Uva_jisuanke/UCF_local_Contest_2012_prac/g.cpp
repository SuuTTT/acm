#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
const int inf=0x3f3f3f3f;
int t;
int n;
int is[59][59];
char s[59];
int judge(int l,int r){
    if(is[l][r]>=0)return is[l][r];
    if(s[l]=='c'){
        if(l==r)return is[l][r]=1;
        return is[l][r]=judge(l+1,r);
    }
    else if(s[l]=='a'){
        for(int i=l+2;i<=r;i++){
            if(s[i]=='b'){
                if(judge(l+1,i-1)&&(i==r||judge(i+1,r)))return is[l][r]=1;
            }
        }
        return is[l][r]=0;
    }
    else return is[l][r]=0;
}
int main(){
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%s",s);
        n=strlen(s);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)is[i][j]=-1;
        }
        if(judge(0,n-1))printf("Pattern %d: More aliens!\n\n",cas);
        else printf("Pattern %d: Still Looking.\n\n",cas);
    }
    return 0;
}
/*

*/
