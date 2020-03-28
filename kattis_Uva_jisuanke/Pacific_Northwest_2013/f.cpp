#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
set<int> s;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    
    while(cin>>n){
        if(n==-1)break;
        s.clear();
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                s.insert(i),s.insert(n/i);
            }
        }
        s.erase(n);
        int tmp=0;
        for(auto t:s)tmp+=t;
        if(tmp==n){
            cout<<n;
            int cnt=0;
            for(auto t:s){
                cout<<' '<<(cnt==0?'=':'+')<<' '<<t;
                cnt++;
            }
            cout<<endl;
        }else{
            cout<<n<<" is NOT perfect."<<endl;
        }

    }
}
/* \
6
12
28
-1
1……6
2……28
3……496
4……8,128
 */
