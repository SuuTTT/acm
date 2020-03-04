#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[51],flag[51],p,lst,cnt;
inline void print(int x,int pp){
    cnt++;
    printf("Page %d loaded into cell %d.\n",x,pp);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;int q;int kase=1;
    while(cin>>n>>q){
        if(n==0&&q==0)break;
        printf("Program %d\n",kase++);
        p=1,lst=1,cnt=0;
        fill(flag,flag+51,0);
        fill(a,a+51,0);
        while(q--){
            int x;cin>>x;
            int ok1=0;
            rep(i,1,n)if(a[i]==x){
                printf("Access page %d in cell %d.\n",x,i);
                ok1=1;
                flag[i]=1;
                break;
            }if(ok1)continue;
            if(lst<=n){
                a[lst]=x;
                print(x,lst);
                flag[lst]=1;
                lst++;
                
            }else{
                //debug(lst);
                while(1){
                    //debug(p),debug(flag[p]);
                    if(flag[p]==2){
                        a[p]=x;
                        flag[p]=1;
                        print(x,p);
                        p++;if(p==n+1)p=1;
                        break;
                    }
                    if(flag[p]==1){
                        flag[p]=2;
                        p++;if(p==n+1)p=1;
                    }
                }
            }
        }
        printf("There are a total of %d page faults.\n\n",cnt);
    }
    
    
    
}
/* 
3 12
3 2 1 5 3 2 4 3 2 1 5 4
5 16
1 3 5 7 9 9 7 5 1 8 3 5 2 3 12 18
8 1
1
0 0

 */