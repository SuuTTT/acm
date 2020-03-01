#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    bitset<64> b;
    int q;cin>>q;while(q--){
        int op;cin>>op;
        int x=0;
        switch (op)
        {
        case 0:
            cin>>x;
            cout<<b.test(x)<<endl;
            break;
        case 1:
            cin>>x;
            b.set(x);
            break;
        case 2:
            cin>>x;
            b.reset(x);
            break;
        case 3:
            cin>>x;
            b.flip(x);
            break;
        case 4:
            cout<<b.all()<<endl;
            break;
        case 5:
            cout<<b.any()<<endl;
            break;
        case 6:
            cout<<b.none()<<endl;
            break;
        case 7:
            cout<<b.count()<<endl;
            break;
        case 8:
            cout<<b.to_ulong()<<endl;
            break;
        default:
            break;
        }
    }
}
/* 
- test(i): Print 1 if ii-th flag is ON, otherwise 0
- set(i): Set ii-th flag to ON
- clear(i): Set ii-th flag to OFF
- flip(i): Inverse ii-th flag
- all: Print 1 if all flags are ON, otherwise 0
- any: Print 1 if at least one flag is ON, otherwise 0
- none: Print 1 if all flags are OFF, otherwise 0
- count: Print the number of ON flags
- val: Print the decimal value of the state

 */