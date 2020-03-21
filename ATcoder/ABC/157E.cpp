#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
set<int> pos[256];
int main(){
   //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    string s;
    cin>>n>>s;

    for(int i=0;i<n;i++){
        pos[s[i]].insert(i+1);
    }
    int q;cin>>q;
    rep(i,1,q){
        int op;cin>>op;
        if(op==1){
            int x;char c;
            cin>>x>>c;
            pos[s[x-1]].erase(x);
            pos[c].insert(x);
            
            s[x-1]=c;
        }else{
            int x,y;cin>>x>>y;
            int ret=0;
            rep(c,'a','z'){
               auto it=pos[c].lower_bound(x);
                //debug(*it);
               if(it!=pos[c].end()&&*it<=y)ret++;
            }
            cout<<ret<<endl;
        }
    }
}
/* 
7
abcdbbd
6
2 3 6
1 5 z
2 1 1
1 4 a
1 7 d
2 1 7
 */