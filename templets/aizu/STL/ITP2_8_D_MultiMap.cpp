#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
multimap<string,int> mp;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;cin>>q;while(q--){
        int op;cin>>op;
        if(op==3){
            string l,r;
            cin>>l>>r;
            auto ed=mp.upper_bound(r);
            for(auto it=mp.lower_bound(l);it!=ed;it++){
                cout<<it->first<<' '<<it->second<<endl;
            }
        }else{
            string s;cin>>s;
            if(op==0){
                int x;cin>>x;
                mp.insert(make_pair(s,x));
                
            }
            if(op==1){
                auto ed=mp.upper_bound(s);
                for(auto it=mp.lower_bound(s);it!=ed;it++){
                    cout<<it->second<<endl;
                }
            }
            if(op==2)mp.erase(s);
        }
        
    }
}
/* 
- insert(keykey, xx): Insert an element formed by a pair of keykey and xx to MM.
- get(keykey): Print the value with the specified keykey. Print 0 if there is no such element.
- delete(keykey): Delete the element with the specified keykey.
- dump(LL, RR): Print all elements formed by a pair of the key and the value such that the key is greater than or equal to LL and less than or equal to RR in lexicographic order..
10
0 blue 6
0 red 1
0 blue 4
0 white 5
1 red
1 blue
2 red
1 black
1 red
3 w z
 */
