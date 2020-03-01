#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int mp[505][505];
list<int> ans;
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    scanf("%d",&t);
    while(t--){
        ans.clear();
        int n;
        scanf("%d",&n);
        rep(i,1,n)rep(j,1,n){
             scanf("%d",&mp[i][j]);
        }
        ans.push_back(1);
        rep(i,2,n){
            for(auto it=ans.end();;it--){
                auto tmp=it;
                tmp--;
                if(mp[*tmp][i]){
                    ans.insert(it,i);
                    break;
                }
                if(tmp==ans.begin()){
                    ans.insert(tmp,i);
                   break; 
                }
            }
        }
        int cnt=1;

        for(auto t:ans){
            printf("%d%c",t,(cnt++==(int)ans.size()?'\n':' '));
        }
    }
}
/* 
1
2
0 1
0 0


2
4
0 1 1 0
0 0 0 1
0 1 0 0
1 0 1 0
3
0 1 1
0 0 1
0 0 0

1
3
0 0 1
1 0 1
0 0 0

 */