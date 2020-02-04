#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=1000005;
int p[4]={6, 28, 496, 8128,};
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        scanf("%d",&x);
        int flag=1;
        for(int i=3;i>=0;i--){
            //debug(p[i]);
            if(x>=p[i]){printf("%d\n",p[i]);flag=0;break;}  
        }
        if(flag)puts("-1");
    }

}