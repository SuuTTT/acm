#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    list<int> L;
    auto it=L.end();
    while(n--){
        int op;
        cin>>op;
        if(op==0){
            int x;cin>>x;
            it=L.insert(it,x);
        }else {
            if(op==1){
                int d;cin>>d;
                if(d>0)while(d--)it++;
                else while(d++)it--;
            }else{
                it=L.erase(it);
            }
        }
    }
    for(auto t:L)cout<<t<<endl;
}

/* 
5
0 1
0 2
0 3
1 1
2
insert(x): Insert x before the element indicated by the cursor. After this operation, the cursor points the inserted element.
move(d): Move the cursor to the end by d, if d is positive. Move the cursor to the front by , if d is negative.
erase(): Delete the element indicated by the cursor. After this operation, the cursor points the element next to the deleted element. In case there is no such element, the cursor should point END.
 */