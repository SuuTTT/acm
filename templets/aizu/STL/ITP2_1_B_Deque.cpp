#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    deque<int> Q;
    int t;cin>>t;
    while(t--){
        int op;
        cin>>op;
        if(op==0){
            int d,x;
            cin>>d>>x;
            !d?Q.push_front(x):Q.push_back(x);
        }else{
            if(op==1){
                int p;
                cin>>p;
                cout<<Q[p]<<endl;
            }else{
                int d;
                cin>>d;
                !d?Q.pop_front():Q.pop_back();
            }
        }
    }
    
}
/* 
- push(dd, xx): Add element xx at the begining of AA, if d=0d=0. Add element xx at the end of AA, if d=1d=1.
- randomAccess(pp): Print element apap.
- pop(dd): Delete the first element of AA, if d=0d=0. Delete the last element of AA, if d=1d=1.
 */