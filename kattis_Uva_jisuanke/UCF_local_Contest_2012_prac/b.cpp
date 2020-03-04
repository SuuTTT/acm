#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
const int inf=0x3f3f3f3f;
int t;
int has[2][28];
char a[109],b[109];
int main(){
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%s%s",a,b);
        for(int i=0;i<26;i++)has[0][i]=has[1][i]=0;
        for(int i=0;a[i]!='\0';i++)has[0][a[i]-'a']++;
        for(int i=0;b[i]!='\0';i++)has[1][b[i]-'a']++;
        int ans=0;
        for(int i=25;i>=0;i--){
            if(has[0][i]==has[1][i])continue;
            if(has[0][i]>has[1][i])ans=1;
            else if(has[0][i]<has[1][i])ans=-1;
            break;
        }
        if(ans==1)printf("Data set #%d: First string is older\n\n",cas);
        else if(ans==-1)printf("Data set #%d: First string is younger\n\n",cas);
        else printf("Data set #%d: The two strings are the same age\n\n",cas);
    }
    return 0;
}
/*

*/
