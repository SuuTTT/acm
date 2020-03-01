#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
set<int> s;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;cin>>q;while(q--){
        int op=0;cin>>op;
        if(op==3){
            int l,r;
            cin>>l>>r;
            auto ed=s.upper_bound(r);
            for(auto it=s.lower_bound(l);it!=ed;it++)cout<<*it<<endl;
        }else{
            int x=0;
            cin>>x;
            if(op==0){s.insert(x);cout<<s.size()<<endl;}
            if(op==1){cout<<s.count(x)<<endl;}
            if(op==2){s.erase(x);}
        }
        
    }
}
/* 

- insert(xx): Insert xx to SS and report the number of elements in SS after the operation.
- find(xx): Report the number of xx in SS (0 or 1).
- delete(xx): Delete xx from SS.
- dump(LL, RR): Print elements xx in SS such that L≤x≤RL≤x≤R.
9
0 1
0 2
0 3
2 2
1 1
1 2
1 3
0 4
3 2 4
 */